/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 15:59:40 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 08:56:26 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long	ft_atol(const char *str)
{
	int		index;
	long	res;
	int		negative;

	negative = 1;
	res = 0;
	index = 0;
	while (ft_istvnrf(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			negative = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = (res * 10) + (str[index] - 48);
		index++;
	}
	return (negative * res);
}
