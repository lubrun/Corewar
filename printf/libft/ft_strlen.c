/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:12:54 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 14:33:54 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	int	chaine;
	int	count;

	chaine = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[chaine] != '\0')
	{
		chaine++;
		count++;
	}
	return (count);
}
