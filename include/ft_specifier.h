/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:47:58 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 12:19:11 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SPECIFIER_H
# define FT_SPECIFIER_H

# include <aio.h>

# define STRALLOC_MAX_BUFFER 64

typedef union u_value
{
	int				as_int;
	unsigned int	as_uint;
	unsigned long	as_ul;
	void			*as_ptr;
	char			*as_str;
	char			as_chr;
}	t_value;

typedef struct s_stralloc
{
	char	buffer[STRALLOC_MAX_BUFFER];
	size_t	size;
	size_t	max;
}	t_stralloc;

typedef struct s_specifier
{
	t_value		value;
	char		sign[2];
	char		hex[3];
	t_stralloc	prefix;
	t_stralloc	suffix;
}	t_specifier;

void	init_specifier(t_specifier *spec);
void	set_value(char cspecifier, t_specifier *spec, void *value);

#endif
