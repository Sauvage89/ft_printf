/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:21:03 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 20:31:22 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_specifier.h"
#include "libft.h"

void	ft_set_hex(char cspecifier, t_specifier *tspecifier)
{
	ft_strcpy(tspecifier->hex, "");
	if (ft_strchr("p", cspecifier))
		ft_strcpy(tspecifier->hex, "0x");
}
