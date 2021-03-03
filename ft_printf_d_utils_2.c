/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:19:09 by abrun             #+#    #+#             */
/*   Updated: 2021/01/14 19:00:48 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_d_n_2(int puissance, int n_point)
{
	while (puissance < n_point && n_point >= 0)
	{
		ft_putchar_fd('0', 1);
		puissance++;
	}
	return (puissance);
}

void		print_d_4(int n_point, int puissance, long int n, int filler)
{
	if (n_point > puissance && n < 0 && filler != '0')
		ft_putchar_fd('-', 1);
}

int			print_d_5(int n_point, int puissance, long int n, int filler)
{
	print_d_4(n_point, puissance, n, filler);
	while (n_point > puissance)
	{
		ft_putchar_fd('0', 1);
		puissance++;
	}
	return (puissance);
}

void		print_d_6(char *num, int n, int n_point, long int nbr)
{
	if (p_p(num, n, n_point))
		ft_putnbr_fd(nbr, 1);
}
