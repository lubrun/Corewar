/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:41:35 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 18:20:14 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int index;
	int compare;

	index = 0;
	compare = 0;
	if (needle[index] == '\0')
		return ((char*)&haystack[index]);
	while (haystack[index])
	{
		while (haystack[index + compare] == needle[compare])
		{
			compare++;
			if (!(needle[compare]))
				return ((char*)&haystack[index]);
		}
		compare = 0;
		index++;
	}
	return (NULL);
}
