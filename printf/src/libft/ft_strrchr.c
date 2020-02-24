/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:22:38 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 16:04:42 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index])
		index++;
	while (index >= 0)
	{
		if (s[index] == (char)c)
			return ((char*)&s[index]);
		index--;
	}
	return (NULL);
}
