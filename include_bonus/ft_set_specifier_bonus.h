/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:43:55 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 17:01:11 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_SPECIFIER_H
# define FT_HANDLE_SPECIFIER_H

typedef struct s_specifier	t_specifier;

void	ft_set_sign(char *flag, char cspecifier, t_specifier *tspecifier);
void	ft_set_hex(char *flag, char cspecifier, t_specifier *tspecifier);
void	ft_set_prefix(char *flag, char cspecifier, t_specifier *tspecifier);
void	ft_set_suffix(char *flag, char cspecifier, t_specifier *tspecifier);

#endif
