/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:19:16 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 17:21:23 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

void	init_specifier(t_specifier *specifier)
{
	specifier->sign[0] = 0;
	specifier->hex[0] = 0;
	specifier->prefix.max = STRALLOC_MAX_BUFFER;
	specifier->prefix.size = 0;
	specifier->suffix.max = STRALLOC_MAX_BUFFER;
	specifier->suffix.size = 0;
}
