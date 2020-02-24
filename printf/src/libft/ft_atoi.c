/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   atoi.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:19:25 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 22:27:06 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		index;
	int		negative;
	long	res;

	res = 0;
	negative = 1;
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
		if (res < 0 && negative == 1)
			return (-1);
		if (res < 0 && negative == -1)
			return (0);
		index++;
	}
	return (negative * res);
}
