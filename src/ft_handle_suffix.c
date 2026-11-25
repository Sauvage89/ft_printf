/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_suffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:28:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 13:10:32 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"
#include "ft_utils.h"
#include "libft.h"

void	set_suffix(char *flag, char cspecifier, t_specifier *spec)
{
	int	nb_flag;

	if (!ft_strnstr(flag, "-", ft_strlen(flag))
		|| ft_strnstr(flag, ".", ft_strlen(flag)))
		return ;
	ft_memset(spec->suffix.buffer, ' ', 64);
	nb_flag = ft_atoi(ft_strrchr(flag, '-') + 1);
	if (cspecifier == 'c')
		nb_flag -= 1;
	else if (cspecifier == 's')
		nb_flag -= ft_strlen(spec->value.as_str);
	else if (cspecifier == 'd' || cspecifier == 'i')
		nb_flag -= len_int(spec->value.as_int);
	else if (ft_strchr("uxXp", cspecifier))
		nb_flag -= len_uint(spec->value.as_uint);
	nb_flag -= ft_strlen(spec->sign);
	if (nb_flag < 0)
		nb_flag = 0;
	spec->suffix.size = nb_flag;
}
