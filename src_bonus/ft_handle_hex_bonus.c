/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:24:16 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 17:00:06 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include "libft.h"

void	ft_set_hex(char *flag, char cspecifier, t_specifier *tspecifier)
{
	ft_strcpy(tspecifier->hex, "");
	if (ft_strchr("p", cspecifier))
		ft_strcpy(tspecifier->hex, "0x");
	else if (ft_strchr("xX", cspecifier)
		&& ft_strnstr(flag, "#", ft_strlen(flag)))
	{
		if (cspecifier == 'x')
			ft_strcpy(tspecifier->hex, "0x");
		else if (cspecifier == 'X')
			ft_strcpy(tspecifier->hex, "0X");
	}
}
