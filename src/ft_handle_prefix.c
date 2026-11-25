/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:27:31 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 17:52:16 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"
#include "ft_utils.h"
#include "libft.h"
#include <stdio.h>

static void	set_prefix_dot_number(char *flag, char cspecifier,
		t_specifier *spec)
{
	char	buffer[18];
	int		nb_flag;

	ft_memset(spec->prefix.buffer, '0', 64);
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
	if (cspecifier == 'd' || cspecifier == 'i')
		nb_flag -= len_int(spec->value.as_int);
	else if (ft_strchr("uxX", cspecifier))
		nb_flag -= len_uint(spec->value.as_uint);
	else if (cspecifier == 'p')
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_uint,
					"0123456789abcdef", buffer));
	if (cspecifier == 'p')
		nb_flag -= ft_strlen(spec->hex);
	if (nb_flag < 0)
		nb_flag = 0;
	spec->prefix.size = nb_flag;
}

static void	set_prefix_dot(char *flag, char cspecifier, t_specifier *spec)
{
	int	nb_flag;

	if (ft_strchr("diuxXp", cspecifier))
		return (set_prefix_dot_number(flag, cspecifier, spec));
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
	if (cspecifier == 's' && (size_t)nb_flag < ft_strlen(spec->value.as_str))
		(spec->value.as_str)[nb_flag] = 0;
}

void	set_prefix(char *flag, char cspecifier, t_specifier *spec)
{
	char	buffer[18];
	int		nb_flag;

	if (ft_strnstr(flag, ".", ft_strlen(flag)))
		return (set_prefix_dot(flag, cspecifier, spec));
	if (ft_strnstr(flag, "-", ft_strlen(flag)) || ft_strchr("cs", cspecifier))
		return ;
	if (!ft_strnstr(flag, "0", ft_strlen(flag)))
		return ;
	ft_memset(spec->prefix.buffer, '0', 64);
	nb_flag = ft_atoi(ft_strchr(flag, '0') + 1);
	if (ft_strchr("di", cspecifier))
		nb_flag -= len_int(spec->value.as_int);
	if (cspecifier == 'u')
		nb_flag -= len_uint(spec->value.as_uint);
	if (cspecifier == 'p')
		nb_flag -= ft_strlen(ft_ulbasetoc(spec->value.as_uint,
					"0123456789abcdef", buffer));
	nb_flag -= ft_strlen(spec->sign);
	nb_flag -= ft_strlen(spec->hex);
	if (nb_flag < 0)
		nb_flag = 0;
	spec->prefix.size = nb_flag;
}
