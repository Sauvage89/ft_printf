/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:06:42 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 13:09:58 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdio.h>

typedef struct s_specifier	t_specifier;
typedef struct s_stralloc	t_stralloc;

ssize_t			ft_putspec_fd(char *format, t_specifier *spec,
					char cspecifier, int fd);
ssize_t			ft_putspec_nzero_fd(char *format, t_specifier *spec,
					char cspecifier, int fd);
ssize_t			ft_putvalue_fd(char *format, t_specifier *spec,
					char cspecifier, int fd);
ssize_t			ft_putnstr_fd(const char *s, size_t len, int fd);
ssize_t			ft_putstralloc_fd(t_stralloc *str, int fd);
ssize_t			ft_putint_nsign_fd(long n, int fd);
ssize_t			ft_putuintbase_fd(unsigned int n, int fd, char *base);
ssize_t			ft_putulbase_fd(unsigned long n, int fd, char *convert);
char			*ft_strcpy(char *dst, const char *src);
unsigned int	len_int(long n);
unsigned int	len_uint(unsigned int n);
char			*ft_ulbasetoc(unsigned long n, const char *base, char *buffer);
int				ft_atoi_prefix(char *flag);

#endif
