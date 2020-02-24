/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:58:22 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 18:03:36 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char*)&s[index]);
		index++;
	}
	if (s[index] == '\0' && c == 0)
		return ((char*)&s[index]);
	return (0);
}
