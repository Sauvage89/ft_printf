/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:52:56 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 20:40:38 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include "libft.h"
#include <stdint.h>

ssize_t	ft_putvalue_fd(t_specifier *spec, char cspecifier, int fd)
{
	if (cspecifier == 'c')
		return (ft_putchar_fd(spec->value.as_chr, fd));
	else if (cspecifier == 's')
		return (ft_putstr_fd(spec->value.as_str, fd));
	else if (cspecifier == 'd')
		return (ft_putint_nsign_fd(spec->value.as_int, fd));
	else if (cspecifier == 'i')
		return (ft_putint_nsign_fd(spec->value.as_int, fd));
	else if (cspecifier == 'u')
		return (ft_putuintbase_fd(spec->value.as_uint, fd, "0123456789"));
	else if (cspecifier == 'x')
		return (ft_putuintbase_fd(spec->value.as_uint, fd, "0123456789abcdef"));
	else if (cspecifier == 'X')
		return (ft_putuintbase_fd(spec->value.as_uint, fd, "0123456789ABCDEF"));
	else if (cspecifier == 'p')
		return (ft_putulbase_fd(spec->value.as_ul, fd, "0123456789abcdef"));
	return (0);
}

ssize_t	ft_putspec_nzero_fd(t_specifier *spec, int fd)
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
	if (spec->prefix.size > 0)
		spec->prefix.size += 1;
	ret_tmp = ft_putstralloc_fd(&spec->prefix, fd);
	if (ret_tmp == -1)
		return (-1);
	ret += ret_tmp;
	ret_tmp = ft_putstralloc_fd(&spec->suffix, fd);
	if (ret_tmp == -1)
		return (-1);
	return (ret + ret_tmp);
}

ssize_t	ft_putspec_fd(t_specifier *spec, char cspecifier, int fd)
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
	ret_tmp = ft_putvalue_fd(spec, cspecifier, fd);
	if (ret_tmp == -1)
		return (-1);
	ret += ret_tmp;
	ret_tmp = ft_putstralloc_fd(&spec->suffix, fd);
	if (ret_tmp == -1)
		return (-1);
	return (ret + ret_tmp);
}
