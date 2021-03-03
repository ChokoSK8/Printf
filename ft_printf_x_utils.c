/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:33:05 by abrun             #+#    #+#             */
/*   Updated: 2020/12/03 09:36:09 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_x_2(int filler, unsigned int n)
{
	if (filler == '0' && n < 0)
		ft_putchar_fd('-', 1);
}

int			print_x_n_1(int n_point, unsigned int n)
{
	if (n_point && n < 0)
	{
		ft_putchar_fd('-', 1);
		return (-1);
	}
	return (0);
}

void		print_x_4(int n_point, int puissance, unsigned int n, int filler)
{
	if (n_point > puissance && n < 0 && filler != '0')
		ft_putchar_fd('-', 1);
}
