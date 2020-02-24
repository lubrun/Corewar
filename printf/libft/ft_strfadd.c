/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfadd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 17:07:06 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 18:55:33 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfadd(char *str, char c, int len)
{
	int index;

	index = 0;
	if (len <= 0)
		return (str);
	while (str[index])
		index++;
	while (index >= 0)
	{
		str[index + len] = str[index];
		index--;
	}
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (str);
}
