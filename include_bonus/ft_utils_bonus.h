/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:06:42 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 21:25:06 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

# include <aio.h>

# define ERROR_WRITE -67
# define ERROR_PARAMPTR_NULL -69
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_16_DOWN "0123456789abcdef"
# define BASE_10 "0123456789"

typedef struct s_specifier	t_specifier;
typedef struct s_stralloc	t_stralloc;

ssize_t			ft_putspec_fd(t_specifier *spec, int fd);
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
ssize_t			ft_putchar_fd(char c, int fd);
ssize_t			ft_putstr_fd(const char *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strnstr(const char *big, const char *little, unsigned int len);
void			*ft_memset(void *s, int c, size_t n);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);


#endif
