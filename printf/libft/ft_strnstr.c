/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:36:24 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 18:22:29 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int index;
	int compare;

	index = 0;
	compare = 0;
	if (little[index] == '\0')
		return ((char*)&big[index]);
	while (big[index] && index < (int)len)
	{
		while (big[index + compare] == little[compare]
				&& (index + compare) < (int)len)
		{
			compare++;
			if (!(little[compare]))
				return ((char*)&big[index]);
		}
		compare = 0;
		index++;
	}
	return (NULL);
}
