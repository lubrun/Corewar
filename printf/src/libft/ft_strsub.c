/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 18:04:03 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 18:26:55 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		index;
	char	*res;

	res = NULL;
	index = 0;
	if (!s)
		return (0);
	while (index < (int)start)
		index++;
	if (!(res = malloc(sizeof(char) * (len) + (1))))
		return (0);
	index = 0;
	while (index < (int)len)
	{
		res[index] = (char)s[index + start];
		index++;
	}
	res[index] = '\0';
	return (res);
}
