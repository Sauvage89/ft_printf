/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:57:08 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 14:30:57 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

void	ft_init_specifier(t_specifier *specifier)
{
	specifier->sign[0] = 0;
	specifier->hex[0] = 0;
}

void	ft_set_value(char cspecifier, t_specifier *spec, void *value)
{
	if (cspecifier == 'c')
		spec->value = (t_value){.as_chr = (char)(unsigned long)value};
	else if (cspecifier == 's')
		spec->value = (t_value){.as_str = (char *)(unsigned long)value};
	if (cspecifier == 'd')
		spec->value = (t_value){.as_int = (int)(unsigned long)value};
	if (cspecifier == 'i')
		spec->value = (t_value){.as_int = (int)(unsigned long)value};
	else if (cspecifier == 'u')
		spec->value = (t_value){.as_uint = (unsigned int)(unsigned long)value};
	else if (cspecifier == 'x')
		spec->value = (t_value){.as_uint = (unsigned int)(unsigned long)value};
	else if (cspecifier == 'X')
		spec->value = (t_value){.as_uint = (unsigned int)(unsigned long)value};
	else if (cspecifier == 'p')
		spec->value = (t_value){.as_ul = (unsigned long)value};
}
