/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:46:30 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/25 17:53:06 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_specifier.h"
#include "libft.h"
#include <stdint.h>

ssize_t	ft_putstralloc_fd(t_stralloc *str, int fd)
{
	size_t	i;
	ssize_t	ret;

	i = 0;
	ret = 0;
	while (i < str->size)
	{
		ret += write(fd, str->buffer, str->size % str->max);
		if ((size_t)ret < str->max && ret % str->size < str->size)
			return (ERROR_WRITE);
		i += str->size % str->max;
	}
	return (ret);
}

ssize_t	ft_putint_nsign_fd(long n, int fd)
{
	char	buffer[12];
	long	n_save;
	uint8_t	len;

	len = 0;
	n_save = n;
	while (n_save != 0)
	{
		n_save /= 10;
		len++;
	}
	buffer[len] = 0;
	while (n != 0)
	{
		len--;
		buffer[len] = n % 10 + '0';
		n /= 10;
	}
	return (ft_putstr_fd(buffer, fd));
}

ssize_t	ft_putuintbase_fd(unsigned int n, int fd, char *convert)
{
	unsigned int	n_save;
	char			buffer[32];
	int				len_n;

	len_n = 0;
	n_save = n;
	while (n_save >= ft_strlen(convert))
	{
		n_save /= ft_strlen(convert);
		len_n++;
	}
	len_n++;
	buffer[len_n] = 0;
	while (len_n > 0)
	{
		len_n--;
		buffer[len_n] = convert[n % ft_strlen(convert)];
		n /= ft_strlen(convert);
	}
	return (ft_putstr_fd(buffer, fd));
}

ssize_t	ft_putulbase_fd(unsigned long n, int fd, char *convert)
{
	unsigned long	n_save;
	char			buffer[32];
	int				len_n;

	len_n = 0;
	n_save = n;
	while (n_save >= ft_strlen(convert))
	{
		n_save /= ft_strlen(convert);
		len_n++;
	}
	len_n++;
	buffer[len_n] = 0;
	while (len_n > 0)
	{
		len_n--;
		buffer[len_n] = convert[n % ft_strlen(convert)];
		n /= ft_strlen(convert);
	}
	return (ft_putstr_fd(buffer, fd));
}

ssize_t	ft_putnstr_fd(const char *s, size_t len, int fd)
{
	ssize_t	ret;
	size_t	len_s;

	if (!s)
		return (ERROR_PARAMPTR_NULL);
	len_s = ft_strlen(s);
	if (len_s > len)
		len_s = len;
	ret = write(fd, s, len_s);
	if (ret < (ssize_t)len_s)
		return (ERROR_WRITE);
	return (ret);
}
