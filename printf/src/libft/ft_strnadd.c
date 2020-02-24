/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnadd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 12:37:10 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 15:41:41 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnadd(char *str, char c, int n)
{
	int index;

	index = 0;
	if (str == NULL)
		return (NULL);
	if (n > 0)
	{
		while (index < n)
		{
			str[index] = c;
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
