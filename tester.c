/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 19:40:03 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 20:44:36 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Compare printf and ft_printf for cspdiuxX ONLY
// (no flags, no width, no precision)
//
// usage : ./tester       -> every test
//         ./tester ko    -> only failed tests
//         ./tester d x ko -> only %d and %x, only failed tests
//
// build : cc tester_specifier.c libftprintf.a -I. -o tester
//
// For every value, 2 formats are tested : "%c" and "start %c end"
// Then some formats with several conversions / no conversion at all.
// A test is OK if printf and ft_printf give the same bytes AND the same
// return value. A crash / timeout of ft_printf is caught (it runs in a child).

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

#define BUF_SIZE 512
#define CONVS "cspdiuxX"
#define COUNT(a) ((int)(sizeof(a) / sizeof((a)[0])))

typedef intptr_t t_arg;
typedef int (*t_printf)(const char *, ...);
typedef int (*t_runner)(t_printf);

typedef struct s_multi
{
	const char	*fmt;
	t_runner	run;
}	t_multi;

static int			g_fd;
static int			g_only_ko;
static int			g_color;
static char			g_filter[16];
static int				g_ok;
static int				g_ko;
static int				g_var = 5;

// Current test
static const char	*g_fmt;
static char			g_conv;
static t_arg			g_arg;

/* ------------------------------------------------------------------ */
/* Display */

int	print_escaped(const char *s, int len)
{
	int	k;
	int	n;

	k = 0;
	n = 0;
	while (k < len)
	{
		if (s[k] == '\n')
			n += printf("\\n");
		else if (isprint((unsigned char)s[k]))
			n += printf("%c", s[k]);
		else
			n += printf("\\x%02x", (unsigned char)s[k]);
		k++;
	}
	return (n);
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

void	print_label(void)
{
	int	n;

	n = print_escaped(g_fmt, strlen(g_fmt));
	while (n++ < 26)
		putchar(' ');
	if (g_conv)
	{
		printf(" arg ");
		print_arg(g_conv, g_arg);
	}
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

/* ------------------------------------------------------------------ */
/* Running */

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

int	run_single(t_printf f)
{
	return (call(f, g_fmt, g_conv, g_arg));
}

int	run_none(t_printf f)
{
	return (f(g_fmt));
}

int	run_all(t_printf f)
{
	return (f(g_fmt, 'a', "hello", (void *)&g_var,
			-52, 52, 42u, 255u, 255u));
}

int	run_3d(t_printf f)
{
	return (f(g_fmt, 1, -2, 3));
}

int	run_3s(t_printf f)
{
	return (f(g_fmt, "a", "", "c"));
}

int	run_3c(t_printf f)
{
	return (f(g_fmt, 'a', 0, 'c'));
}

int	run_text(t_printf f)
{
	return (f(g_fmt, "Bob", 42, 255u));
}

// Run in a child with stdout redirected to a temporary file.
// Returns the printf return value or -signal if the child crashed.

int	capture(t_runner run, t_printf f, char *out, int *len)
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
		exit(run(f));
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

void	run_test(const char *fmt, char conv, t_arg arg, t_runner run)
{
	char	real[BUF_SIZE];
	char	mine[BUF_SIZE];
	int		len_r;
	int		len_m;
	int		ret_r;
	int		ret_m;
	int		ok;

	g_fmt = fmt;
	g_conv = conv;
	g_arg = arg;
	ret_r = capture(run, printf, real, &len_r);
	ret_m = capture(run, ft_printf, mine, &len_m);
	ok = (ret_r == ret_m && len_r == len_m
			&& !memcmp(real, mine, len_r));
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
	print_label();
	print_result("real", real, len_r, ret_r);
	print_result("mine", mine, len_m, ret_m);
	printf("\n");
}

/* ------------------------------------------------------------------ */
/* Tests */

// Test "%c" and "start %c end" for every value

void	test_conv(char conv, t_arg *vals, int nb)
{
	char	fmt[32];
	int		v;

	if (g_filter[0] && !strchr(g_filter, conv))
		return ;
	printf("\n========== test %%%c ==========\n", conv);
	v = 0;
	while (v < nb)
	{
		snprintf(fmt, sizeof(fmt), "%%%c", conv);
		run_test(fmt, conv, vals[v], run_single);
		snprintf(fmt, sizeof(fmt), "start %%%c end", conv);
		run_test(fmt, conv, vals[v], run_single);
		v++;
	}
	printf("========== end %%%c ==========\n", conv);
}

// Multiple conversions and formats without conversions

void	test_multi(void)
{
	t_multi	tests[] = {
		{"", run_none},
		{"hello world", run_none},
		{"%c|%s|%p|%d|%i|%u|%x|%X", run_all},
		{"%c%s%p%d%i%u%x%X", run_all},
		{"%d %d %d", run_3d},
		{"%i%i%i", run_3d},
		{"%s%s%s", run_3s},
		{"%c%c%c", run_3c},
		{"Hello %s, %d years, 0x%x\n", run_text},
	};
	int	k;

	if (g_filter[0])
		return ;
	printf("\n========== test multi conversions ==========\n");
	k = 0;
	while (k < COUNT(tests))
	{
		run_test(tests[k].fmt, 0, 0, tests[k].run);
		k++;
	}
	printf("========== end multi conversions ==========\n");
}

void	test_all(void)
{
	t_arg	c[] = {'a', '0', ' ', '\n', 0, 127, -50, 255};
	t_arg	s[] = {
		(t_arg)"hello",
		(t_arg)"",
		(t_arg)" ",
		(t_arg)NULL,
		(t_arg)"a much longer string with spaces and 123 numbers",
		(t_arg)"%d",
		(t_arg)"line1\nline2",
		(t_arg)"\xce\x05\x11\xee\x80\x7f"
	};
	t_arg	p[] = {
		(t_arg)&g_var, 0, 1, 16, 52, -52,
		INTPTR_MAX, INTPTR_MIN, -1
	};
	t_arg	d[] = {
		0, 1, -1, 9, 10, -10, 42, -42, 100, 1234567,
		INT_MAX, INT_MIN, INT_MAX - 1, INT_MIN + 1
	};
	t_arg	u[] = {
		0, 1, 9, 10, 42, 100, -1, -42, INT_MAX, INT_MIN,
		(t_arg)UINT_MAX
	};
	t_arg	x[] = {
		0, 1, 9, 10, 15, 16, 255, 256, 4096, -1, -42,
		INT_MAX, INT_MIN, (t_arg)UINT_MAX
	};

	test_conv('c', c, COUNT(c));
	test_conv('s', s, COUNT(s));
	test_conv('p', p, COUNT(p));
	test_conv('d', d, COUNT(d));
	test_conv('i', d, COUNT(d));
	test_conv('u', u, COUNT(u));
	test_conv('x', x, COUNT(x));
	test_conv('X', x, COUNT(x));
	test_multi();
}

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
		else if (strlen(av[i]) == 1 && strchr(CONVS, (int)(unsigned long)av[i])
			&& strlen(g_filter) < sizeof(g_filter) - 1)
			strncat(g_filter, av[i], 1);
		i++;
	}
	test_all();
	printf("\nTOTAL : %d tests, %d OK, %d KO\n",
		g_ok + g_ko, g_ok, g_ko);
	return (g_ko != 0);
}

/*
int	main()
{
	printf("last nb %i\n", ft_printf("'%%ppt%%tr%it\n'", 5));
	printf("last nb %i\n", printf("'%%ppt%%tr%it\n'", 5));
}*/
