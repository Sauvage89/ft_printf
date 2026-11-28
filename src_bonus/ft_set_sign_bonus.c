/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sign_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 16:11:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 20:50:18 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"

void	ft_set_sign(t_specifier *spec)
{
	if (spec->asflag.as_sign == 0)
		return ;
	if (ft_strchr(spec->flag, '+')
		&& (ft_strchr("p", spec->converter)
		|| (ft_strchr("id", spec->converter) && spec->value.as_int >= 0)))
		ft_strcpy(spec->sign, "+");
	else if (ft_strchr(spec->flag, ' ')
		&& (ft_strchr("p", spec->converter)
		|| (ft_strchr("id", spec->converter) && spec->value.as_int >= 0)))
		ft_strcpy(spec->sign, " ");
	if (ft_strchr("id", spec->converter)
		&& spec->value.as_int < 0)
		ft_strcpy(spec->sign, "-");
}
