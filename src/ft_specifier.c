/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:19:16 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 17:56:18 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_handle_specifier.h"
#include "ft_specifier.h"
#include "ft_utils.h"
#include "libft.h"

void	init_specifier(t_specifier *specifier)
{
	specifier->sign[0] = 0;
	specifier->hex[0] = 0;
	specifier->prefix.max = STRALLOC_MAX_BUFFER;
	specifier->prefix.size = 0;
	specifier->suffix.max = STRALLOC_MAX_BUFFER;
	specifier->suffix.size = 0;
}

void	set_value(char cspecifier, t_specifier *spec, void *value)
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

void	ft_print_specifier(char *flag, char cspecifier, void *value)
{
	t_specifier	spec;

	init_specifier(&spec);
	set_value(cspecifier, &spec, value);
	set_sign(flag, cspecifier, &spec);
	set_hex(flag, cspecifier, &spec);
	set_prefix(flag, cspecifier, &spec);
	set_suffix(flag, cspecifier, &spec);
	ft_putstr_fd(spec.sign, 1);
	ft_putstr_fd(spec.hex, 1);
	ft_putstralloc_fd(&spec.prefix, 1);
	ft_putvalue_fd(&spec, cspecifier, 1);
	ft_putstralloc_fd(&spec.suffix, 1);
}
