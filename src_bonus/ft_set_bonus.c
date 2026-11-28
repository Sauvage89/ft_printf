/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:19:16 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:54:20 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set_specifier_bonus.h"
#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include <unistd.h>

static void	ft_set_value(t_specifier *spec, void *value)
{
	if (spec->converter == 'c')
		spec->value = (t_value){.as_chr = (char)(unsigned long)value};
	else if (spec->converter == 's')
		spec->value = (t_value){.as_str = (char *)(unsigned long)value};
	if (spec->converter == 'd')
		spec->value = (t_value){.as_int = (int)(unsigned long)value};
	if (spec->converter == 'i')
		spec->value = (t_value){.as_int = (int)(unsigned long)value};
	else if (spec->converter == 'u')
		spec->value = (t_value){.as_uint = (unsigned int)(unsigned long)value};
	else if (spec->converter == 'x')
		spec->value = (t_value){.as_uint = (unsigned int)(unsigned long)value};
	else if (spec->converter == 'X')
		spec->value = (t_value){.as_uint = (unsigned int)(unsigned long)value};
	else if (spec->converter == 'p')
		spec->value = (t_value){.as_ul = (unsigned long)value};
}

static void	ft_set_asflag(t_specifier *spec)
{
	spec->asflag.as_width = 1;
	spec->asflag.as_sign = 1;
	spec->asflag.as_hex = 1;
	spec->asflag.as_prefix = 0;
	spec->asflag.as_value = 1;
	spec->asflag.as_suffix = 0;
	if ((ft_strchr(spec->flag, '0')
		&& !ft_strchr(spec->flag, '-') && !ft_strchr("cs", spec->converter))
		|| ft_strchr(spec->flag, '.'))
		spec->asflag.as_prefix = 1;
	if ((ft_strchr(spec->flag, '0') && !ft_strchr(spec->flag, '.'))
		|| ft_strchr(spec->flag, '-'))
		spec->asflag.as_width = 0;
	if (ft_strchr(spec->flag, '-'))
		spec->asflag.as_suffix = 1;
	if (ft_strchr(spec->flag, '.') && ft_strchr("i", spec->converter)
		&& spec->value.as_int == 0
		&& ft_atoi(ft_strnstr(spec->flag, ".", ft_strlen(spec->flag)) + 1) == 0)
		spec->asflag.as_value = 0;
}

void	ft_set_specifier(t_specifier *spec, char *flag, char cspecifier, void *value)
{
	spec->flag = flag;
	spec->converter = cspecifier;
	spec->sign[0] = 0;
	spec->hex[0] = 0;
	spec->prefix.max = STRALLOC_MAX_BUFFER;
	spec->prefix.size = 0;
	spec->suffix.max = STRALLOC_MAX_BUFFER;
	spec->suffix.size = 0;
	spec->width.max = STRALLOC_MAX_BUFFER;
	spec->width.size = 0;
	ft_set_value(spec, value);
	ft_set_asflag(spec);
}
