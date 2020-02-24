/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 15:31:55 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:23:12 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** traduit le nombre en signe de 0 a f.
*/

static char	ft_convert(unsigned long long nomber)
{
	char c;

	if (nomber < 10)
		c = nomber + '0';
	else
		c = nomber + 'a' - 10;
	return (c);
}

/*
** securise avec count on remplit de la fin au debut.
*/

static char	*ft_make_str(unsigned long long nomber, int base, char *str,
		int count)
{
	char	c;

	str[count--] = '\0';
	while (nomber != 0 && count >= 0)
	{
		c = ft_convert(nomber % base);
		str[count--] = c;
		nomber = nomber / base;
	}
	return (str);
}

/*
** bien penser a faire str = itoa_base puis free(str)
*/

char		*ft_ulltoa_base(unsigned long long value, int base)
{
	unsigned long long	nomber;
	char				*str;
	int					count;

	count = 0;
	nomber = value;
	if (nomber == 0)
	{
		if (((str = malloc(sizeof(char) * (2))) == NULL))
			return (0);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (nomber)
	{
		count++;
		nomber = nomber / base;
	}
	nomber = value;
	if (((str = malloc(sizeof(char) * (count + 1))) == NULL))
		return (0);
	return (ft_make_str(nomber, base, str, count));
}
