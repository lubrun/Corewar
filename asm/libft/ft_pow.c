/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 12:40:06 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 11:37:57 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int pow)
{
	int		x;
	int		res;
	int		sign;

	sign = 0;
	if (pow == 0)
		return (1);
	else if (pow < 0)
	{
		pow *= -1;
		sign = 1;
	}
	x = 0;
	res = 1;
	while (x < pow)
	{
		if (sign == 0)
			res *= n;
		else
			res *= n / pow;
		x++;
	}
	return (res);
}
