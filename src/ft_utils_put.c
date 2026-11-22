/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:46:30 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 19:20:48 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_tspecifier.h"
#include "libft.h"

void	ft_putstrspecifier_fd(t_stralloc *tstr, int fd)
{
	unsigned int	i;

	if (tstr->buffer[0] == 0)
		return ;
	i = 0;
	while (i < tstr->size)
	{
		write(fd, tstr->buffer, tstr->size % tstr->max);
		i += tstr->size % tstr->max;
	}
}

void	ft_putvinbspecifier_fd(long n, int fd)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
