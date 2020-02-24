/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:50:53 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:17:35 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strrev(char *res, int count, int negative)
{
	int		index;
	int		max;
	char	swap;

	max = count - 2 + negative;
	index = 0;
	while (index < (count / 2))
	{
		swap = res[index];
		res[index] = res[max];
		res[max] = swap;
		index++;
		max--;
	}
	return (res);
}

static char	*ft_makestr(char *res, long n, int count, int negative)
{
	int		index;
	long	nomber;

	nomber = n;
	index = 0;
	while (index < (count - 1))
	{
		res[index] = (nomber % 10 + '0');
		nomber = nomber / 10;
		index++;
	}
	if (negative)
	{
		res[index] = '-';
		index++;
	}
	res[index] = '\0';
	return (ft_strrev(res, count, negative));
}

static char	*ft_isnegative(char *res, int count, int negative, long n)
{
	long nomber;

	nomber = n;
	if (n < 0)
	{
		negative = 1;
		if (n == -2147483648)
			nomber = 2147483648;
		else
			nomber = -n;
		return (ft_makestr(res, nomber, count, negative));
	}
	return (ft_makestr(res, n, count, negative));
}

char		*ft_itoa(int n)
{
	char	*res;
	long	nomber;
	int		count;
	int		negative;

	negative = 0;
	count = 2;
	nomber = n;
	res = NULL;
	while (nomber / 10)
	{
		count++;
		nomber = nomber / 10;
	}
	if (n < 0)
		negative = 1;
	if (!(res = (char*)malloc(sizeof(char) * (count + negative))))
		return (0);
	return (ft_isnegative(res, count, negative, n));
}
