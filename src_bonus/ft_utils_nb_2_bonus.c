/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nb_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 18:51:20 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 18:51:47 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		sign = 44 - nptr[i++];
	while (ft_isdigit(nptr[i]))
	{
		if (nb * 10 + nptr[i] - '0' < nb && sign == 1)
			return (-1);
		if (nb * 10 + nptr[i] - '0' < nb - 1 && sign == -1)
			return (0);
		nb = nb * 10 + nptr[i++] - '0';
	}
	return (nb * sign);
}
