/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_suffix_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:28:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 17:00:36 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include "libft.h"

static void	set_suffix_len(char *flag, char cspecifier, t_specifier *spec)
{
	char	buffer[19];
	int		nb_flag;

	nb_flag = ft_atoi(flag);
	if (cspecifier == 'c')
		nb_flag -= 1;
	else if (cspecifier == 's')
		nb_flag -= ft_strlen(spec->value.as_str);
	else if (ft_strchr("di", cspecifier))
		nb_flag -= len_int(spec->value.as_int);
	else if (ft_strchr("u", cspecifier))
		nb_flag -= len_uint(spec->value.as_uint);
	else if (ft_strchr("xX", cspecifier))
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_uint,
					"0123456789abcdef", buffer));
	else if (cspecifier == 'p')
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_ul,
					"0123456789abcdef", buffer));
	nb_flag -= ft_strlen(spec->sign);
	nb_flag -= ft_strlen(spec->hex);
	nb_flag -= spec->prefix.size;
	if (nb_flag < 0)
		nb_flag = 0;
	spec->suffix.size = nb_flag;
}

void	ft_set_suffix(char *flag, char cspecifier, t_specifier *spec)
{
	if (!ft_strnstr(flag, "-", ft_strlen(flag)))
		return ;
	ft_memset(spec->suffix.buffer, ' ', 64);
	set_suffix_len(flag, cspecifier, spec);
}
