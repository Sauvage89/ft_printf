/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:26:19 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 17:47:27 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	len_int(long n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

unsigned int	len_uint(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

char	*ft_ulbasetoc(unsigned long n, const char *base, char *buffer)
{
	unsigned long	n_save;
	int				count;

	count = 0;
	n_save = n;
	while (n_save >= (unsigned long)ft_strlen(base))
	{
		count++;
		n_save /= ft_strlen(base);
	}
	count++;
	buffer[count] = 0;
	while (count > 1)
	{
		count--;
		buffer[count] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (buffer);
}
