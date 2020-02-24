/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 12:42:02 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 12:51:04 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *zone;

	zone = NULL;
	if ((zone = (void*)malloc(sizeof(void*) * size)) == NULL)
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
