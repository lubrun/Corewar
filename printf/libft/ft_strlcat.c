/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:01:06 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 14:38:36 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizesup(char *restrict dst, const char *restrict src,
		int fulllen, size_t size)
{
	int length;
	int index;

	index = 0;
	length = -1;
	while (index < (int)size && dst[index])
		index++;
	if (size >= (ft_strlen(dst) + ft_strlen((char*)src)))
	{
		while (src[length++ + 1] && (index + length + 1) < (int)size)
			dst[index + length] = src[length];
		dst[index + length] = '\0';
		return (fulllen);
	}
	while (src[length++ + 1] && (length + index) < (int)size - 1)
		dst[index + length] = src[length];
	dst[index + length] = '\0';
	return (fulllen);
}

size_t			ft_strlcat(char *restrict dst, const char *restrict src,
		size_t size)
{
	int index;
	int length;
	int fulllen;

	fulllen = ft_strlen(src) + ft_strlen(dst);
	length = -1;
	index = 0;
	if (size + 1 <= ft_strlen(dst))
		return (ft_strlen((char*)src) + (int)size);
	if (dst[index] == '\0')
	{
		ft_strncpy(dst, src, size - 1);
		return (ft_strlen((char*)src));
	}
	return (ft_sizesup(dst, src, fulllen, size));
}
