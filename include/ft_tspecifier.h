/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tspecifier.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:47:58 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 18:48:34 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_TSPECIFIER_H
# define FT_TSPECIFIER_H

typedef struct s_stralloc
{
	char			buffer[64];
	unsigned int	size;
	unsigned int	max;
}	t_stralloc;

typedef struct s_specifier
{
	void	*value;
	char	sign[2];
	char	hex[3];
	t_stralloc	prefix;
	t_stralloc	sufix;
}	t_specifier;

#endif
