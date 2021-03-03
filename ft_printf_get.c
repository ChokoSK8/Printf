/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:35:14 by abrun             #+#    #+#             */
/*   Updated: 2021/01/14 18:38:30 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int		get_res(int puissance, int n_chr)
{
	if (puissance > n_chr)
		return (puissance);
	return (n_chr);
}

int		get_res_s(int puissance, int n_chr, int n_point)
{
	if (n_point >= 0 && n_point >= n_chr && n_point <= puissance)
		return (n_point);
	if (n_point >= 0 && n_point <= puissance && n_point <= n_chr)
		return (n_chr);
	if (puissance > n_chr)
		return (puissance);
	return (n_chr);
}

int		get_res_npt(int puissance, int n_chr, int n_point, int space_plus)
{
	space_plus ? n_chr++ : n_chr;
	space_plus ? n_point++ : n_point;
	space_plus && puissance >= n_chr ? puissance++ : puissance;
	if (puissance >= n_point && puissance > n_chr)
		return (puissance);
	else if (n_point > puissance && n_point > n_chr)
		return (n_point);
	return (n_chr);
}

int		get_res_npt_pos(int n, int n_chr, int n_point, int space_plus)
{
	int		puissance;

	puissance = ft_putpui(n, 10);
	n < 0 ? puissance-- : puissance;
	space_plus ? n_chr++ : n_chr;
	space_plus || n < 0 ? n_point++ : n_point;
	(n < 0 || space_plus) && puissance >= n_chr ? puissance++ : puissance;
	if (puissance >= n_point && puissance > n_chr)
		return (puissance);
	else if (n_point >= puissance && n_point > n_chr)
		return (n_point);
	return (n_chr);
}

int		get_res_npt_neg(int n, int n_chr, int n_point, int space_plus)
{
	int		puissance;

	puissance = ft_putpui(n, 10);
	space_plus ? n_chr++ : n_chr;
	space_plus || n < 0 ? n_point++ : n_point;
	space_plus && puissance >= n_chr && n >= 0 ? puissance++ : puissance;
	if (puissance >= n_point && puissance > n_chr)
		return (puissance);
	else if (n_point >= puissance && n_point > n_chr)
		return (n_point);
	return (n_chr);
}
