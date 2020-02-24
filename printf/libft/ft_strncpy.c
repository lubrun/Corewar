/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:20:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 16:07:01 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int index;

	index = 0;
	if ((int)len == 0)
		return (dst);
	while (src[index] && index < (int)len)
	{
		dst[index] = src[index];
		index++;
	}
	while (index < (int)len)
	{
		dst[index] = '\0';
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
