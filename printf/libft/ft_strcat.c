/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:35:35 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:38:40 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int	index;
	int length;

	length = 0;
	index = 0;
	while (s1[index])
		index++;
	while (s2[length])
	{
		s1[index + length] = s2[length];
		length++;
	}
	s1[index + length] = '\0';
	return (s1);
}
