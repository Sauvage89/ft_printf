/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 18:43:19 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/28 18:58:44 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"
#include <unistd.h>

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	ret;
	size_t	len;

	if (!s)
		return (ERROR_PARAMPTR_NULL);
	len = ft_strlen(s);
	ret = write(fd, s, len);
	if (ret < (ssize_t)len)
		return (ERROR_WRITE);
	return (ret);
}
