/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_precision_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 16:47:25 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 19:52:42 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "libft.h"

static void	set_precision_number(char *flag, char cspecifier,
		t_specifier *spec)
{
	int	nb_flag;

	(void)cspecifier;
	ft_memset(spec->prefix.buffer, '0', 64);
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
}

void	ft_set_prefix_dot(char *flag, char cspecifier, t_specifier *spec)
{
	int	nb_flag;

	(void)cspecifier;
	if (ft_strchr("diuxXp", cspecifier))
		return (set_precision_number(flag, cspecifier, spec));
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
}
