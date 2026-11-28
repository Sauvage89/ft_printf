/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:47:58 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 20:03:39 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SPECIFIER_BONUS_H
# define FT_SPECIFIER_BONUS_H

# include <aio.h>
# include <stdbool.h>
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

typedef struct s_asflag
{
	bool	as_width;
	bool	as_sign;
	bool	as_hex;
	bool	as_prefix;
	bool	as_value;
	bool	as_suffix;
}	t_asflag;

typedef struct s_specifier
{
	char		converter;
	char		*flag;
	t_asflag	asflag;
	t_stralloc	width;
	char		sign[2];
	char		hex[3];
	t_stralloc	prefix;
	t_value		value;
	t_stralloc	suffix;
}	t_specifier;

#endif
