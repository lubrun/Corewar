/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:10:17 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 17:13:49 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*res;

	res = NULL;
	index = 0;
	if (s)
	{
		if (!(res = malloc(sizeof(char) * (ft_strlen((void*)s) + (1)))))
			return (0);
		while (s[index])
		{
			res[index] = f(index, (char)s[index]);
			index++;
		}
		res[index] = '\0';
	}
	return (res);
}
