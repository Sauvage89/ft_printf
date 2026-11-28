/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:24:16 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 20:48:58 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"

void	ft_set_hex(t_specifier *spec)
{
	if (spec->asflag.as_hex == 0)
		return ;
	if (ft_strchr("p", spec->converter))
		ft_strcpy(spec->hex, "0x");
	else if (ft_strchr("xX", spec->converter) && ft_strchr(spec->flag, '#')
		&& spec->converter == 'x')
		ft_strcpy(spec->hex, "0x");
	else if (ft_strchr("xX", spec->converter) && ft_strchr(spec->flag, '#')
		&& spec->converter == 'X')
		ft_strcpy(spec->hex, "0X");
}
