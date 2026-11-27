/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 16:11:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 12:23:18 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"
#include "ft_utils.h"
#include "libft.h"

void	set_sign(char *flag, char cspecifier, t_specifier *tspecifier)
{
	ft_strcpy(tspecifier->sign, "");
	if (ft_strchr("id", cspecifier)
		&& ft_strnstr(flag, "+", ft_strlen(flag))
		&& tspecifier->value.as_int >= 0)
		ft_strcpy(tspecifier->sign, "+");
	else if (ft_strchr("id", cspecifier)
		&& ft_strnstr(flag, " ", ft_strlen(flag))
		&& tspecifier->value.as_int >= 0)
		ft_strcpy(tspecifier->sign, " ");
	if (ft_strchr("p", cspecifier) && ft_strnstr(flag, "+", ft_strlen(flag)))
		ft_strcpy(tspecifier->sign, "+");
	else if (ft_strchr("p", cspecifier)
		&& ft_strnstr(flag, " ", ft_strlen(flag)))
		ft_strcpy(tspecifier->sign, " ");
	if (ft_strchr("id", cspecifier)
		&& tspecifier->value.as_int < 0)
		ft_strcpy(tspecifier->sign, "-");
}
