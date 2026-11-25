/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:52:56 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 18:00:33 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_specifier.h"
#include "ft_utils.h"
#include "libft.h"
#include <stdint.h>

void	ft_putvalue_fd(t_specifier *spec, char cspecifier, int fd)
{
	if (cspecifier == 'c')
		ft_putchar_fd(spec->value.as_chr, fd);
	else if (cspecifier == 's')
		ft_putstr_fd(spec->value.as_str, fd);
	else if (cspecifier == 'd')
		ft_putint_nsign_fd(spec->value.as_int, fd);
	else if (cspecifier == 'i')
		ft_putint_nsign_fd(spec->value.as_int, fd);
	else if (cspecifier == 'u')
		ft_putuintbase_fd(spec->value.as_uint, fd, "0123456789");
	else if (cspecifier == 'x')
		ft_putuintbase_fd(spec->value.as_uint, fd, "0123456789abcdef");
	else if (cspecifier == 'X')
		ft_putuintbase_fd(spec->value.as_uint, fd, "0123456789ABCDEF");
	else if (cspecifier == 'p')
		ft_putulbase_fd(spec->value.as_ul, fd, "0123456789abcdef");
}
