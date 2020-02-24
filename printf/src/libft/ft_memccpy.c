/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:31:15 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:12:15 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	int index;

	index = 0;
	while (index < (int)n)
	{
		((unsigned char*)dst)[index] = ((unsigned char*)src)[index];
		if ((unsigned char)c == ((unsigned char*)src)[index])
			return (&dst[index + 1]);
		index++;
	}
	return (NULL);
}
