/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_specifier.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:58:33 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 20:31:07 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SET_SPECIFIER_H
# define FT_SET_SPECIFIER_H

typedef struct s_specifier	t_specifier;

void	ft_set_sign(char cspecifier, t_specifier *tspecifier);
void	ft_set_hex(char cspecifier, t_specifier *tspecifier);

#endif
