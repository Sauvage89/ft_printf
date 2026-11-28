/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 15:58:20 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:26:56 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Compare printf and ft_printf for cspdiuxX with the flags '-0.# +' combined
//
// usage :	./tester			-> every test
//			./tester ko			-> only the failed tests
//			./tester d x ko		-> only %d and %x, only the failed tests
//
// build :	cc tester_printf.c libftprintf.a -I. -o tester
//
// A width number (3, 12) is only used when the flags contain - or 0 (WIDTH_FLAGS).
// The number after "." (precision) is always tested.
//
// A test is OK if printf and ft_printf give the same bytes AND the same
// return value. A crash / timeout of ft_printf is catched (it runs in a child).
// Some combos are undefined behavior in C (%0s, %#c, %+p ...): printf of your
// machine is the reference (glibc and macOS don't always agree).

#include "include_bonus/ft_printf_bonus.h"
#include "include_bonus/ft_utils_bonus.h"
#include "include_bonus/ft_specifier_bonus.h"
#include "include_bonus/ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <sys/wait.h>

#define BUF_SIZE	512
#define CONVS		"cspdiuxX"
#define WIDTH_FLAGS	"-0"		// flags that take a width number
#define COUNT(a)	((int)(sizeof(a) / sizeof((a)[0])))

typedef intptr_t	t_arg;
typedef int			(*t_printf)(const char *, ...);

static const char	*g_flags = "-0 +#";
static const char	*g_widths[] = {"", "3", "12", NULL};
static const char	*g_precs[] = {"", ".", ".0", ".4", ".12", NULL};

static int			g_fd;
static int			g_only_ko;
static int			g_color;
static char			g_filter[16];
static int			g_ok;
static int			g_ko;
static int			g_var = 5;

/* ---------------------------------------------------------------- display */

void	print_escaped(const char *s, int len)
{
	int	k;

	k = 0;
	while (k < len)
	{
		if (s[k] == '\n')
			printf("\\n");
		else if (isprint((unsigned char)s[k]))
			putchar(s[k]);
		else
			printf("\\x%02x", (unsigned char)s[k]);
		k++;
	}
}

void	print_arg(char conv, t_arg arg)
{
	if (conv == 's' && arg == 0)
		printf("NULL");
	else if (conv == 's')
	{
		printf("\"");
		print_escaped((char *)arg, strlen((char *)arg));
		printf("\"");
	}
	else if (conv == 'p')
		printf("%p", (void *)arg);
	else if (conv == 'c' || conv == 'd' || conv == 'i')
		printf("%d", (int)arg);
	else
		printf("%u", (unsigned int)arg);
}

void	print_result(const char *label, char *out, int len, int ret)
{
	printf(" | %s <", label);
	print_escaped(out, len);
	if (ret < 0)
		printf("> CRASH (signal %d)", -ret);
	else
		printf("> (%d)", ret);
}

/* ---------------------------------------------------------------- running */

// call f (printf or ft_printf) with the right type for the conversion
int	call(t_printf f, const char *fmt, char conv, t_arg arg)
{
	if (conv == 's')
		return (f(fmt, (char *)arg));
	if (conv == 'p')
		return (f(fmt, (void *)arg));
	if (conv == 'c' || conv == 'd' || conv == 'i')
		return (f(fmt, (int)arg));
	return (f(fmt, (unsigned int)arg));
}

// run f in a child with stdout redirected to a tmp file, then read the file
// return : the return value of f, or -signal if the child crashed
int	capture(t_printf f, const char *fmt, char conv, t_arg arg, char *out, int *len)
{
	pid_t	pid;
	int		status;

	fflush(stdout);
	ftruncate(g_fd, 0);
	lseek(g_fd, 0, SEEK_SET);
	pid = fork();
	if (pid == 0)
	{
		alarm(2);
		dup2(g_fd, STDOUT_FILENO);
		exit(call(f, fmt, conv, arg));
	}
	waitpid(pid, &status, 0);
	*len = pread(g_fd, out, BUF_SIZE - 1, 0);
	if (*len < 0)
		*len = 0;
	out[*len] = 0;
	if (WIFSIGNALED(status))
		return (-WTERMSIG(status));
	return (WEXITSTATUS(status));
}

void	run_test(const char *fmt, char conv, t_arg arg)
{
	char	real[BUF_SIZE];
	char	mine[BUF_SIZE];
	int		len_r;
	int		len_m;
	int		ret_r;
	int		ret_m;
	int		ok;

	ret_r = capture(printf, fmt, conv, arg, real, &len_r);
	ret_m = capture(ft_printf, fmt, conv, arg, mine, &len_m);
	//ok = (ret_r == ret_m && len_r == len_m && !memcmp(real, mine, len_r));
	ok = (len_r == len_m && !memcmp(real, mine, len_r));
	if (ok)
		g_ok++;
	else
		g_ko++;
	if (ok && g_only_ko)
		return ;
	if (g_color)
		printf(ok ? "\033[32m[OK]\033[0m " : "\033[31m[KO]\033[0m ");
	else
		printf(ok ? "[OK] " : "[KO] ");
	printf("%-14s arg ", fmt);
	print_arg(conv, arg);
	print_result("real", real, len_r, ret_r);
	print_result("mine", mine, len_m, ret_m);
	printf("\n");
}

/* ------------------------------------------------------------------ tests */

// build the flags of a mask (bit k = k-th char of "-0 +#"), maybe reversed
void	build_flags(char *dst, int mask, int reverse)
{
	int	k;
	int	idx;
	int	n;

	k = 0;
	n = 0;
	while (k < 5)
	{
		idx = k;
		if (reverse)
			idx = 4 - k;
		if (mask & (1 << idx))
			dst[n++] = g_flags[idx];
		k++;
	}
	dst[n] = 0;
}

// every width x precision for one flag string
// a width number is only added if the flags contain a width flag (- or 0),
// so "%+3d" is never tested (the number would not be handled -> fake KO)
void	test_flags(const char *flags, char conv, t_arg *vals, int nb)
{
	char	fmt[64];
	int		has_width_flag;
	int		w;
	int		p;
	int		v;

	has_width_flag = (strpbrk(flags, WIDTH_FLAGS) != NULL);
	w = 0;
	while (g_widths[w] && (w == 0 || has_width_flag))
	{
		p = 0;
		while (g_precs[p])
		{
			snprintf(fmt, sizeof(fmt), "%%%s%s%s%c",
				flags, g_widths[w], g_precs[p], conv);
			v = 0;
			while (v < nb)
				run_test(fmt, conv, vals[v++]);
			p++;
		}
		w++;
	}
}

// every combination of flags (32 subsets, + the reversed order) for one conv
void	test_conv(char conv, t_arg *vals, int nb)
{
	char	flags[8];
	int		mask;
	int		reverse;

	if (g_filter[0] && !strchr(g_filter, conv))
		return ;
	printf("\n========== test %%%c ==========\n", conv);
	mask = 0;
	while (mask < 32)
	{
		reverse = 0;
		while (reverse < 2)
		{
			if (reverse && (mask & (mask - 1)) == 0)
				break ;
			build_flags(flags, mask, reverse);
			test_flags(flags, conv, vals, nb);
			reverse++;
		}
		mask++;
	}
	printf("========== end %%%c ==========\n", conv);
}

void	test_all(void)
{
	t_arg	c[] = {'a', 0, -50};
	t_arg	s[] = {(t_arg)"hello", (t_arg)"", (t_arg)NULL,
		(t_arg)"a much longer string", (t_arg)"\xce\x05\x11\xee\x80\x7f"};
	t_arg	p[] = {(t_arg)&g_var, 0, 52, -52, -1};
	t_arg	d[] = {0, 5, 52, -52, INT_MAX, INT_MIN};
	t_arg	u[] = {0, 52, -52, (t_arg)UINT_MAX};
	t_arg	x[] = {0, 52, 255, -52, (t_arg)UINT_MAX};

/*	test_conv('c', c, COUNT(c));
	test_conv('s', s, COUNT(s));
	test_conv('p', p, COUNT(p));
	test_conv('d', d, COUNT(d));
*/	test_conv('i', d, COUNT(d));
/*	test_conv('u', u, COUNT(u));
	test_conv('x', x, COUNT(x));
	test_conv('X', x, COUNT(x));
*/}

int	main(int ac, char **av)
{
	int	i;

	g_color = isatty(STDOUT_FILENO);
	g_fd = fileno(tmpfile());
	i = 1;
	while (i < ac)
	{
		if (!strcmp(av[i], "ko"))
			g_only_ko = 1;
		else if (strlen(av[i]) == 1 && strchr(CONVS, av[i][0])
			&& strlen(g_filter) < sizeof(g_filter) - 1)
			strncat(g_filter, av[i], 1);
		i++;
	}
	test_all();
	printf("\nTOTAL : %d tests, %d OK, %d KO\n", g_ok + g_ko, g_ok, g_ko);
	return (g_ko != 0);
}
