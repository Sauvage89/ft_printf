/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sign_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 16:11:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 17:00:26 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier_bonus.h"
#include "ft_utils_bonus.h"
#include "libft.h"

void	ft_set_sign(char *flag, char cspecifier, t_specifier *tspecifier)
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
