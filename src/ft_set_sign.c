/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:53:53 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 14:20:19 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

void	ft_set_sign(char *flag, char cspecifier, t_specifier *tspecifier)
{
	ft_strcpy(tspecifier->sign, "");
	if (ft_strchr("id", cspecifier)
		&& tspecifier->value.as_int < 0)
		ft_strcpy(tspecifier->sign, "-");
}
