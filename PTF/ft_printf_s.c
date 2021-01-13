/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:41:21 by abrun             #+#    #+#             */
/*   Updated: 2021/01/12 18:03:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*get_null_s(char *s, int *puissance, int n_point)
{
	if (n_point > 6)
		n_point = 6;
	if (!(s = ft_strdup("(null)", n_point)))
		return (0);
	*puissance = ft_strlen(s);
	return (s);
}

int			print_s_normal(char *s, int n_chr, char *num)
{
	int			n_point;
	int			filler;
	int			puissance;
	int			res;

	res = 0;
	puissance = ft_strlen(s);
	n_point = get_flag_point_s(num, puissance);
	if (puissance < 0)
		if (!(s = get_null_s(s, &puissance, n_point)))
			return (-1);
	res = get_res_s(puissance, n_chr, n_point);
	filler = 32;
	if (is_flag_zero(num))
		filler = '0';
	if (is_flag_point(num) && puissance > n_point)
		puissance = n_point;
	n_chr = print_c_3(n_chr, puissance, filler);
	print_s_npt(n_point, s, puissance, num);
	return (res);
}

int			print_s_neg(char *s, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			res;

	res = 0;
	puissance = ft_strlen(s);
	n_point = get_flag_point_s(num, puissance);
	if (puissance < 0)
		if (!(s = get_null_s(s, &puissance, n_point)))
			return (-1);
	res = get_res_s(puissance, n_chr, n_point);
	if (is_flag_point(num) && puissance > n_point)
		puissance = n_point;
	print_s_npt(n_point, s, puissance, num);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	return (res);
}

int			print_s(char *s, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (num[0] != '-')
		return (print_s_normal(s, n_chr, num));
	else
		return (print_s_neg(s, n_chr, num));
}
