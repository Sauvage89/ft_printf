/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nb_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:26:19 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:39:56 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

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

int	ft_atoi_prefix(char *flag)
{
	while (*flag && ft_strchr("-0# +%", *flag))
		flag++;
	if (*flag == '.')
		return (0);
	return (ft_atoi(flag));
}

int	ft_atoi_printf_rev(char *flag)
{
	int	i;
	int	j;

	i = 0;
	if (flag[i])
		i++;
	if (i != 0)
		i -= 2;
	while (i >= 0 && flag[i])
	{
		while (i >= 0 && ft_strchr("-.# +%", *flag))
			i--;
		while (i >= 0)
		{
			while (i >= 0 && ft_isdigit(flag[i]) && flag[i] != '0')
				i--;
			j = i;
			while (j >= 0 && flag[j] == '0')
				j--;
			if (j >= 0 && !ft_isdigit(flag[j]))
				return (ft_atoi(flag + j));
			i = j;
		}
	}
	return (ft_atoi(flag + i));
}
