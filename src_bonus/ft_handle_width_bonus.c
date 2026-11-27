/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 16:50:03 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 17:00:46 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include "libft.h"
#include <stdint.h>

void	ft_set_width(char *flag, char cspecifier,
		t_specifier *spec, int width)
{
	char	buffer[18];

	if (cspecifier == 's' && (size_t)width < ft_strlen(spec->value.as_str))
		(spec->value.as_str)[width] = 0;
	if (ft_strchr("di", cspecifier))
		width -= len_int(spec->value.as_int);
	if (ft_strchr("u", cspecifier))
		width -= len_uint(spec->value.as_uint);
	if (ft_strchr("xX", cspecifier))
		width -= ft_strlen(ft_ulbasetoc(spec->value.as_uint,
					"0123456789abcdef", buffer));
	if (cspecifier == 'p')
		width -= ft_strlen(ft_ulbasetoc(spec->value.as_ul,
					"0123456789abcdef", buffer));
	if (ft_strnstr(flag, "0", ft_strlen(flag)))
	{
		width -= ft_strlen(spec->sign);
		width -= ft_strlen(spec->hex);
	}
	if (width < 0)
		width = 0;
	spec->prefix.size = width;
}
