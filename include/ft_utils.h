/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:06:42 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 19:13:23 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_UTILS_H
# define FT_UTILS_H

typedef struct s_stralloc t_stralloc;

void			ft_putstrspecifier_fd(t_stralloc *tstr, int fd);
void			ft_putvinbspecifier_fd(long n, int fd);
char			*ft_strcpy(char *dst, const char *src);
unsigned int	len_inb(long nb);
unsigned int	len_unb(unsigned int nb);

#endif
