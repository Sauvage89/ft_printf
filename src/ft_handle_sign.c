/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 16:11:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 19:17:00 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tspecifier.h"
#include "ft_utils.h"
#include "libft.h"

void	set_sign(char *flag, char cspecifier, t_specifier *tspecifier)
{
	ft_strcpy(tspecifier->sign, "");
	if (cspecifier == 'c' || cspecifier == 's'
			|| cspecifier == 'u' || cspecifier == 'x' || cspecifier == 'X')
		return ;
	if (cspecifier == 'p')
		ft_strcpy(tspecifier->sign, "+");
	else if (ft_strnstr(flag, "+", ft_strlen(flag)))
	{
		if (*(int *)(tspecifier->value) >= 0)
			ft_strcpy(tspecifier->sign, "+");
		else
			ft_strcpy(tspecifier->sign, "-");
	}
	else if (ft_strnstr(flag, " ", ft_strlen(flag)))
	{
		if (*(int *)(tspecifier->value) >= 0)
			ft_strcpy(tspecifier->sign, " ");
		else
			ft_strcpy(tspecifier->sign, "-");
	}
	else if (*(int *)(tspecifier->value) < 0)
		ft_strcpy(tspecifier->sign, "-");
}
