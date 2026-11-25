/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:24:16 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/24 11:47:03 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"
#include "ft_utils.h"
#include "libft.h"

void	set_hex(char *flag, char cspecifier, t_specifier *tspecifier)
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
