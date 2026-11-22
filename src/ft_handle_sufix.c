/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sufix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:28:54 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 19:17:59 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tspecifier.h"
#include "ft_utils.h"
#include "libft.h"

void	set_sufix(char *flag, char cspecifier, t_specifier *tspecifier)
{
	int	nb_flag;

	if (!ft_strnstr(flag, "-", ft_strlen(flag)) || ft_strnstr(flag, ".", ft_strlen(flag)))
		return ;
	ft_memset(tspecifier->sufix.buffer, ' ', 64);
	nb_flag = ft_atoi(ft_strrchr(flag, '-') + 1);
	if (cspecifier == 'c')
		nb_flag -= 1;
	else if (cspecifier == 's')
		nb_flag -= ft_strlen((char *)tspecifier->value);
	else if (cspecifier == 'd' || cspecifier == 'i')
	{
		nb_flag -= len_inb(*(int *)tspecifier->value);
	}
	else if (cspecifier == 'u' || cspecifier == 'x' || cspecifier == 'X' || cspecifier == 'p')
		nb_flag -= len_unb(*(unsigned int *)tspecifier->value);
	nb_flag -= ft_strlen(tspecifier->sign);
	if (nb_flag < 0)
		nb_flag = 0;
	tspecifier->sufix.size = nb_flag;
}
