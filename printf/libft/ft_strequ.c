/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strequ.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:15:42 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 17:33:28 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[index] || s2[index])
	{
		if (ft_strcmp((char*)s1, (char*)s2))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
