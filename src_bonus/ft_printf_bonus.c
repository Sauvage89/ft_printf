/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:39:25 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:13:45 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_utils_bonus.h"
#include "ft_specifier_bonus.h"
#include "ft_set_specifier_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

static int	ft_verifier(const char *format)
{
	size_t	i;

	format++;
	i = 0;
	while (format[i] && ft_strchr(" -0#+", format[i]))
		i++;
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

static ssize_t	ft_print_specifier(char *flag, char cspecifier, void *value)
{
	t_specifier	spec;

	ft_set_specifier(&spec, flag, cspecifier, value);
	if (spec.converter == 's' && spec.value.as_str == 0)
		return (ft_putstr_fd("(null)", 1));
	if (spec.converter == 'p' && spec.value.as_ptr == 0)
		return (ft_putstr_fd("(nil)", 1));
	ft_set_width(&spec);
	ft_set_sign(&spec);
	ft_set_hex(&spec);
	ft_set_prefix(&spec);
	ft_set_suffix(&spec);
	return (ft_putspec_fd(&spec, 1));
}

static ssize_t	ft_dispatch(const char **format, va_list ap, size_t *ret)
{
	void	*ap_val;
	int		len;
	ssize_t	ret_tmp;
	char	*buffer;

	len = ft_verifier(*format);
	if (len == 1)
	{
		(void)ap;
		ret_tmp = ft_putchar_fd('%', 1);
	}
	else
	{
		ap_val = va_arg(ap, void *);
		buffer = ft_substr(*format, 0, len);
		ret_tmp = ft_print_specifier(buffer, (*format)[len - 1], ap_val);
		free(buffer);
	}
	if (ret_tmp == -1)
		return (-1);
	*format += len;
	*ret += ret_tmp;
	return (ret_tmp);
}

static int	ft_printf_while(const char **format, va_list ap)
{
	ssize_t	ret_tmp;
	size_t	ret;

	ret = 0;
	ret_tmp = 0;
	while (**format && ret_tmp != -1)
	{
		ret_tmp = (ssize_t)ft_strchr(*format, '%');
		if (ret_tmp == 0)
			break ;
		ret_tmp = ft_putnstr_fd(*format,
				(unsigned long)ret_tmp - (unsigned long)*format, 1);
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
	if ((ssize_t)ret != -1)
		ret_tmp = ft_putstr_fd((char *)format, 1);
	if (ret_tmp == -1 || (ssize_t)ret == -1)
		return (-1);
	ret += (size_t)ret_tmp;
	return (ret);
}
