/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 13:46:39 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 14:28:21 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *zone;

	zone = NULL;
	if ((zone = (char*)malloc(sizeof(void) * size + 1)) == NULL)
		return (NULL);
	ft_bzero(zone, size);
	zone[size] = '\0';
	return (zone);
}
