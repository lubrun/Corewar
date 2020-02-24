/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_endcpy.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 12:51:54 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 14:27:36 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_endcpy(char *dest, char *src)
{
	int		index;
	size_t	len;

	index = 0;
	if (!dest)
		return (NULL);
	if (src[0] == '\0')
	{
		dest[0] = '\0';
		return (dest);
	}
	if ((ft_strlen(dest) < (len = ft_strlen(src))))
		return (ft_strcpy(dest, src));
	while (dest[index])
		index++;
	while ((int)len >= 0 && index >= 0)
	{
		dest[index] = src[len];
		index--;
		len--;
	}
	return (dest);
}
