/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_specifier_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:43:55 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:14:17 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SET_SPECIFIER_BONUS_H
# define FT_SET_SPECIFIER_BONUS_H

typedef struct s_specifier	t_specifier;

void	ft_set_sign(t_specifier *spec);
void	ft_set_hex(t_specifier *spec);
void	ft_set_prefix(t_specifier *spec);
void	ft_set_suffix(t_specifier *spec);
void	ft_set_width(t_specifier *spec);
void	ft_set_specifier(t_specifier *spec,
		char *flag, char cspecifier, void *value);

#endif
