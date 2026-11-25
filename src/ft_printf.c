/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:39:25 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 17:32:12 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_print.h"
#include "ft_utils.h"
#include "ft_specifier.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

static int	ft_verifier(const char *format)
{
	size_t	i;
	bool	is_width;

	format++;
	i = 0;
	is_width = 0;
	while (format[i] && ft_strchr(" -0#+", format[i]))
	{
		if (ft_strchr("-0.", format[i]))
			is_width = 1;
		i++;
	}
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
		i++;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] && ft_strchr("csdiuxXp%", format[i]))
		return (i + 2);
	return (1);
}

static ssize_t	ft_dispatch(const char **format, va_list ap, size_t *ret)
{
	void	*ap_val;
	int	len;
	ssize_t	ret_tmp;

	len = ft_verifier(*format);
	if (len == 1)
	{
		(void)ap;
		ret_tmp = ft_putchar_fd('%', 1);
	}
	else
	{
		ap_val = va_arg(ap, void *);
		ft_print_specifier((char *)*format, (*format)[len - 1], ap_val);
	}
	*format += len;
	*ret += ret_tmp;
	return (ret_tmp);
}


int	ft_printf_while(const char **format, va_list ap)
{
	ssize_t	ret_tmp;
	size_t	ret;
	
	ret = 0;
	ret_tmp = 0;
	while (**format && ret_tmp != -1)
	{
		ret_tmp = (ssize_t)ft_strchr(*format, '%');
		if (ret_tmp == 0)
			return (ret_tmp);
		ret_tmp = ft_putnstr_fd(*format, (unsigned long)ret_tmp - (unsigned long)*format, 1);
		if (ret_tmp == -1)
			return (ret_tmp);
		*format = *format + ret_tmp;
		ret += (size_t)ret_tmp;
		ret_tmp = ft_dispatch(format, ap, &ret);
	}
	if (ret_tmp == -1)
		return (-1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	size_t	ret;
	ssize_t	ret_tmp;
	va_list	ap;

	ret = 0;
	ret_tmp = 0;
	va_start(ap, format);
	ret = ft_printf_while(&format, ap);
	va_end(ap);
	if (ret != -1)
		ret_tmp = ft_putstr_fd((char *)format, 1);
	if (ret_tmp == -1 || ret == -1)
		return (-1);
	ret += (size_t)ret_tmp;
	return (ret);
}

int	main()
{

	ft_printf("yo sa va %i\n", "prout");
	return (0);
}
