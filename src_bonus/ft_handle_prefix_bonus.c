/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prefix_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:27:31 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 17:17:28 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include "libft.h"
#include <stdio.h>

void	ft_set_prefix(char *flag, char cspecifier, t_specifier *spec)
{
	int	width;

	(void)cspecifier;
	if (ft_strnstr(flag, "-", ft_strlen(flag)))
		return ;
	if (ft_strnstr(flag, "0", ft_strlen(flag)))
		ft_memset(spec->prefix.buffer, '0', 64);
	else
		ft_memset(spec->prefix.buffer, ' ', 64);
	width = ft_atoi_prefix(flag);
}
