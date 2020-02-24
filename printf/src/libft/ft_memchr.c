/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 16:36:17 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:46:57 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int index;

	index = 0;
	while (index < (int)n)
	{
		if (((unsigned char*)s)[index] == (unsigned char)c)
			return (((unsigned char*)s + index));
		index++;
	}
	return (NULL);
}
