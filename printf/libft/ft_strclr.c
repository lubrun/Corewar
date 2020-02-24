/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 14:35:04 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 14:45:48 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int index;
	int len;

	index = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (index <= len)
		{
			s[index] = '\0';
			index++;
		}
	}
}
