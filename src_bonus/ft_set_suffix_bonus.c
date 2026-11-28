/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_suffix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:28:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:31:52 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"

void	ft_set_suffix(t_specifier *spec)
{
	char	buffer[19];
	int		nb_flag;

	if (spec->asflag.as_suffix == 0)
		return ;
	ft_memset(spec->suffix.buffer, ' ', 64);
	nb_flag = ft_atoi(spec->flag);
	if (spec->converter == 'c')
		nb_flag -= 1;
	else if (spec->converter == 's')
		nb_flag -= ft_strlen(spec->value.as_str);
	else if (ft_strchr("di", spec->converter))
		nb_flag -= len_int(spec->value.as_int);
	else if (ft_strchr("u", spec->converter))
		nb_flag -= len_uint(spec->value.as_uint);
	else if (ft_strchr("xX", spec->converter))
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_uint, BASE_16_UP, buffer));
	else if (spec->converter == 'p')
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_ul, BASE_16_UP, buffer));
	nb_flag -= ft_strlen(spec->sign) - ft_strlen(spec->hex) - spec->prefix.size;
	if (nb_flag < 0)
		nb_flag = 0;
	spec->suffix.size = nb_flag;
}
