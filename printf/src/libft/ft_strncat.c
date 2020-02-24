/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:34:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:52:15 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int index;
	int length;

	length = 0;
	index = 0;
	while (s1[index])
		index++;
	while (length < ((int)n) && s2[length])
	{
		s1[index + length] = s2[length];
		length++;
	}
	s1[index + length] = '\0';
	return (s1);
}
