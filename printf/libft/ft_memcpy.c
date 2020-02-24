/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:16:00 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:04:34 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int index;

	index = 0;
	while (index < (int)n)
	{
		((unsigned char*)dst)[index] = ((unsigned char*)src)[index];
		index++;
	}
	return (dst);
}
