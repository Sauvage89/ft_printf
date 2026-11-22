/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:26:19 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 18:30:34 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len_inb(long nb)
{
	unsigned int	count;

	count = 0;
	if (nb < 0)
		nb *= -1;
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	count++;
	return (count);
}

unsigned int	len_unb(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	count++;
	return (count);
}
