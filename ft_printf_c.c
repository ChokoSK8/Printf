/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:50:58 by abrun             #+#    #+#             */
/*   Updated: 2021/03/03 15:28:07 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		p_p_c(char *num, unsigned char n, int n_point)
{
	if (is_flag_point(num) && !n && !n_point)
		return (0);
	return (1);
}

int		print_c_normal(unsigned char n, int n_chr, char *num)
{
	int			n_point;
	int			filler;
	int			puissance;
	int			res;

	puissance = 1;
	n_point = get_flag_point(num);
	res = get_res(puissance, n_chr);
	filler = 32;
	if (is_flag_zero(num))
		filler = '0';
	n_chr = print_c_3(n_chr, puissance, filler);
	if (p_p_c(num, n, n_point))
		write(1, &n, 1);
	return (res);
}

int		print_c_neg(unsigned char n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	int			res;

	puissance = 1;
	n_point = get_flag_point(num);
	res = get_res(puissance, n_chr);
	filler = get_filler(num, n_point);
	if (p_p_c(num, n, n_point))
		write(1, &n, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	return (res);
}

int		print_c(unsigned char n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (!is_flag_minus(num))
		return (print_c_normal(n, n_chr, num));
	else
		return (print_c_neg(n, n_chr, num));
}
