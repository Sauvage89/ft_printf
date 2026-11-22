/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:27:31 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 19:14:59 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tspecifier.h"
#include "ft_utils.h"
#include "libft.h"

static void	set_prefix_dot_number(char *flag, char cspecifier, t_specifier *tspecifier)
{
	int	nb_flag;
	
	ft_memset(tspecifier->prefix.buffer, '0', 64);
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
	if (cspecifier == 'd' || cspecifier == 'i')
		nb_flag -= len_inb(*(int *)tspecifier->value);
	else if (cspecifier == 'u' || cspecifier == 'x' || cspecifier == 'X' || cspecifier == 'p')
		nb_flag -= len_unb(*(unsigned int *)tspecifier->value);
	if (nb_flag < 0)
		nb_flag = 0;
	tspecifier->prefix.size = nb_flag;
}

static void	set_prefix_dot(char *flag, char cspecifier, t_specifier *tspecifier)
{
	int	nb_flag;
	
	if (cspecifier == 'd' || cspecifier == 'i' || cspecifier == 'u' || cspecifier == 'x' || cspecifier == 'X' || cspecifier == 'p')
		return (set_prefix_dot_number(flag, cspecifier, tspecifier));
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
	if (cspecifier == 's' && (size_t)nb_flag < ft_strlen(tspecifier->value))
		((char *)tspecifier->value)[nb_flag] = 0;
}

void	set_prefix(char *flag, char cspecifier, t_specifier *tspecifier)
{
	int	nb_flag;

	if (ft_strnstr(flag, ".", ft_strlen(flag)))
		return (set_prefix_dot(flag, cspecifier, tspecifier));
	if (ft_strnstr(flag, "-", ft_strlen(flag)))
		return ;
	if (!ft_strnstr(flag, "0", ft_strlen(flag)))
		return ;
	ft_memset(tspecifier->prefix.buffer, '0', 64);
	nb_flag = ft_atoi(ft_strchr(flag, '0') + 1);
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
	tspecifier->prefix.size = nb_flag;
}
