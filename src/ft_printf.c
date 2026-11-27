/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:24:35 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 20:32:58 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_specifier.h"
#include "ft_set_specifier.h"
#include "ft_utils.h"
#include <stdlib.h>
#include <stdarg.h>

static size_t	ft_verifier(const char *format)
{
	size_t	i;

	format++;
	i = 0;
	if (format[i] && ft_strchr("csdiuxXp%", format[i]))
		return (i + 2);
	return (1);
}

static ssize_t	ft_print_specifier(char cspecifier, void *value)
{
	t_specifier	spec;

	ft_init_specifier(&spec);
	ft_set_value(cspecifier, &spec, value);
	if (cspecifier == 's' && spec.value.as_str == 0)
		return (ft_putstr_fd("(null)", 1));
	if (cspecifier == 'p' && spec.value.as_ptr == 0)
		return (ft_putstr_fd("(nil)", 1));
	ft_set_sign(cspecifier, &spec);
	ft_set_hex(cspecifier, &spec);
	return (ft_putspec_fd(&spec, cspecifier, 1));
}

size_t	ft_dispatch(const char **format, va_list ap, size_t *ret)
{
	void	*ap_val;
	size_t	len;
	size_t	ret_tmp;

	if (**format == 0)
		return (0);
	ret_tmp = 0;
	len = ft_verifier(*format);
	if (len == 1 || (len == 2 && (*format)[1] == '%'))
		ret_tmp = ft_putchar_fd('%', 1);
	else if ((*format)[1] != '%')
	{
		ap_val = va_arg(ap, void *);
		ret_tmp = ft_print_specifier((*format)[len - 1], ap_val);
	}
	if (ret_tmp < 0)
		return (ret_tmp);
	*format += (int)len;
	*ret += ret_tmp;
	return (ret_tmp);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	ret;
	size_t	ret_tmp;

	ret = 0;
	ret_tmp = 0;
	va_start(ap, format);
	while (*format && ret_tmp >= 0)
	{
		ret_tmp = (size_t)ft_strchr(format, '%');
		if (ret_tmp == 0)
			ret_tmp = ft_putstr_fd(format, 1);
		else
			ret_tmp = ft_putnstr_fd(format, ret_tmp - (size_t)format, 1);
		if ((ssize_t)ret_tmp == -1)
			break ;
		format = format + ret_tmp;
		ret += (size_t)ret_tmp;
		ret_tmp = ft_dispatch(&format, ap, &ret);
	}
	va_end(ap);
	if (ret_tmp < 0)
		return (ret_tmp);
	return (ret);
}
