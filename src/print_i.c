/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:28:00 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/22 19:19:03 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_handle_tspecifier.h"
#include "ft_tspecifier.h"
#include "ft_utils.h"
#include "libft.h"

void	print_i(char *flag, int value)
{
	t_specifier	tspecifier;

	tspecifier.value = &value;
	tspecifier.prefix.max = 64;
	tspecifier.prefix.size = 0;
	tspecifier.sufix.max = 64;
	tspecifier.sufix.size = 0;
	set_sign(flag, 'i', &tspecifier);
	set_hex(flag, 'i', &tspecifier);
	set_prefix(flag, 'i', &tspecifier);
	set_sufix(flag, 'i', &tspecifier);
	ft_putstr_fd(tspecifier.sign, 1);
	ft_putstr_fd(tspecifier.hex, 1);
	ft_putstrspecifier_fd(&tspecifier.prefix, 1);
	ft_putvinbspecifier_fd(value, 1);
	ft_putstrspecifier_fd(&tspecifier.sufix, 1);
}
/*
int	main()
{
	int	i = 50;
	
	print_i("%-4i\n", i);
	return (0);
}*/
