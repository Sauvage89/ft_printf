/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_prefix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:27:31 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:48:37 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include <stdio.h>

static void	ft_set_size_prefix_zero(t_specifier *spec)
{
	char	buffer[19];
	int		nb_flag;

	nb_flag = ft_atoi_prefix(spec->flag + 1);
	if (ft_strchr("di", spec->converter))
		nb_flag -= len_int(spec->value.as_int);
	if (spec->converter == 'u')
		nb_flag -= len_uint(spec->value.as_uint);
	if (spec->converter == 'p')
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_uint,
					"0123456789abcdef", buffer));
	nb_flag -= ft_strlen(spec->sign);
	nb_flag -= ft_strlen(spec->hex);
	if (nb_flag < 0)
		nb_flag = 0;
	spec->prefix.size = nb_flag;
}

static void	ft_set_size_prefix_dot(t_specifier *spec)
{
	char	buffer[19];
	int		nb_flag;

	nb_flag = ft_atoi(ft_strrchr(spec->flag, '.') + 1);
	if (spec->converter == 's' && (size_t)nb_flag < ft_strlen(spec->value.as_str))
		(spec->value.as_str)[nb_flag] = 0;
	if (spec->converter == 'd' || spec->converter == 'i')
		nb_flag -= len_int(spec->value.as_int);
	else if (ft_strchr("uxX", spec->converter))
		nb_flag -= len_uint(spec->value.as_uint);
	else if (spec->converter == 'p')
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_uint,
					"0123456789abcdef", buffer));
	if (spec->converter == 'p')
		nb_flag -= ft_strlen(spec->hex);
	if (nb_flag < 0)
		nb_flag = 0;
	spec->prefix.size = nb_flag;
}

void	ft_set_prefix(t_specifier *spec)
{
	if (spec->asflag.as_prefix == 0)
		return ;
	ft_memset(spec->prefix.buffer, '0', 64);
	if (ft_strchr(spec->flag, '0'))
		ft_set_size_prefix_zero(spec);
	if (ft_strchr(spec->flag, '.'))
		ft_set_size_prefix_dot(spec);
}
