/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 16:14:04 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:06:40 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	char	c;

	if (&src[0] < &dst[0] && &src[len] > &dst[0])
	{
		index = len - 1;
		while (index > 0)
		{
			c = ((unsigned char*)src)[index];
			((unsigned char*)dst)[index] = c;
			index--;
		}
		c = ((unsigned char*)src)[index];
		((unsigned char*)dst)[index] = c;
		return (dst);
	}
	index = 0;
	while (index < len)
	{
		c = ((unsigned char*)src)[index];
		((unsigned char*)dst)[index] = c;
		index++;
	}
	return (dst);
}
