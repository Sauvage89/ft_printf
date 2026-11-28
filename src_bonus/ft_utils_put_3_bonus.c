/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put_3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:52:56 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:24:52 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include <stdint.h>

static ssize_t	ft_putvalue_fd(t_specifier *spec, int fd)
{
	if (spec->converter == 'c')
		return (ft_putchar_fd(spec->value.as_chr, fd));
	else if (spec->converter == 's')
		return (ft_putstr_fd(spec->value.as_str, fd));
	else if (spec->converter == 'd')
		return (ft_putint_nsign_fd(spec->value.as_int, fd));
	else if (spec->converter == 'i')
		return (ft_putint_nsign_fd(spec->value.as_int, fd));
	else if (spec->converter == 'u')
		return (ft_putuintbase_fd(spec->value.as_uint, fd, BASE_10));
	else if (spec->converter == 'x')
		return (ft_putuintbase_fd(spec->value.as_uint, fd, BASE_16_DOWN));
	else if (spec->converter == 'X')
		return (ft_putuintbase_fd(spec->value.as_uint, fd, BASE_16_UP));
	else if (spec->converter == 'p')
		return (ft_putulbase_fd(spec->value.as_ul, fd, BASE_16_DOWN));
	return (0);
}

ssize_t	ft_putspec_fd(t_specifier *spec, int fd)
{
	ssize_t		ret;
	ssize_t		ret_tmp;

	ret = ft_putstr_fd(spec->sign, fd);
	if (ret == -1)
		return (-1);
	ret_tmp = ft_putstr_fd(spec->hex, fd);
	if (ret_tmp == -1)
		return (-1);
	ret += ret_tmp;
	ret_tmp = ft_putstralloc_fd(&spec->prefix, fd);
	if (ret_tmp == -1)
		return (-1);
	ret += ret_tmp;
	if (spec->asflag.as_value == 1)
		ret_tmp = ft_putvalue_fd(spec, fd);
	if (ret_tmp == -1)
		return (-1);
	ret += ret_tmp;
	ret_tmp = ft_putstralloc_fd(&spec->suffix, fd);
	if (ret_tmp == -1)
		return (-1);
	return (ret + ret_tmp);
}
