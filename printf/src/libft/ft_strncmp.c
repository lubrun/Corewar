/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:58:42 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:11:02 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int chaine;

	chaine = 0;
	while ((s1[chaine] || s2[chaine]) && chaine < (int)n)
	{
		if ((s1[chaine] - s2[chaine]) != 0)
			return ((unsigned char)s1[chaine] - (unsigned char)s2[chaine]);
		chaine++;
	}
	return (0);
}
