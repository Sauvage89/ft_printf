/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:03:24 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/24 11:38:50 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_HANDLE_TSPECIFIER_H
# define FT_HANDLE_TSPECIFIER_H

typedef struct s_specifier t_specifier;

void	set_sign(char *flag, char cspecifier, t_specifier *tspecifier);
void	set_hex(char *flag, char cspecifier, t_specifier *tspecifier);
void	set_prefix(char *flag, char cspecifier, t_specifier *tspecifier);
void	set_suffix(char *flag, char cspecifier, t_specifier *tspecifier);

#endif
