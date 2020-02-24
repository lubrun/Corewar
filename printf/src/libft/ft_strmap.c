/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:19:46 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:18:36 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*res;

	res = NULL;
	index = 0;
	if (s)
	{
		if (!(res = (char*)malloc(sizeof(char) *
						(ft_strlen((void*)s) + (1)))))
			return (0);
		while (s[index])
		{
			res[index] = f((char)s[index]);
			index++;
		}
		res[index] = '\0';
	}
	return (res);
}
