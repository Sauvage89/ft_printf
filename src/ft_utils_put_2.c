/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:50:14 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 20:32:01 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_specifier.h"
#include "libft.h"

static ssize_t	ft_putvalue_fd(t_specifier *spec,
		char cspecifier, int fd)
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
	ret_tmp = ft_putvalue_fd(spec, cspecifier, fd);
	if (ret_tmp == -1)
		return (-1);
	ret += ret_tmp;
	return (ret);
}
