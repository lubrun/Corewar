/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_isconvert.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 11:59:30 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 15:09:53 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

int		ft_isconvert(const char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 'd' || str[index] == 'i' || str[index] == 'o'
		|| str[index] == 'u' || str[index] == 'x' || str[index] == 'X'
		|| str[index] == 'f' || str[index] == 'c' || str[index] == 's'
		|| str[index] == 'p' || str[index] == '%')
			return (index);
		index++;
	}
	return (0);
}

char	ft_str_isconvert(const char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 'd' || str[index] == 'i' || str[index] == 'o'
		|| str[index] == 'u' || str[index] == 'x' || str[index] == 'X'
		|| str[index] == 'f' || str[index] == 'c' || str[index] == 's'
		|| str[index] == 'p' || str[index] == '%')
			return (str[index]);
		index++;
	}
	return (0);
}
