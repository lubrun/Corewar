/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 13:25:58 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 15:08:35 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		index;

	str = NULL;
	index = 0;
	if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (0);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
