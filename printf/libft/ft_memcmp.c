/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcmp.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 16:53:42 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:13:05 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int index;

	index = 0;
	while (((unsigned char*)s1 || (unsigned char*)s2) && index < (int)n)
	{
		if ((((unsigned char*)s1)[index] - ((unsigned char*)s2)[index]) != 0)
			return (((unsigned char*)s1)[index] - ((unsigned char*)s2)[index]);
		index++;
	}
	return (0);
}
