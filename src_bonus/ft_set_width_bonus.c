/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 16:50:03 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:01:36 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include <stdint.h>

void	ft_set_width(t_specifier *spec)
{
	if (spec->asflag.as_width == 0)
		return ;
	ft_memset(spec->width.buffer, ' ', 64);
}
