/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 18:27:50 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 17:00:27 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	char	*res;
	int		len;
	int		suite;

	suite = 0;
	index = 0;
	res = NULL;
	len = ft_strlen((void*)s1) + ft_strlen((void*)s2) + 1;
	if (!(res = (char*)malloc(sizeof(char*) * (len))))
		return (0);
	if (s1)
		ft_strcpy(res, s1);
	if (s2)
	{
		if (s1)
			ft_strcat(res, s2);
		else
			ft_strcpy(res, s2);
	}
	if (!s1 && !s2)
		res[index + suite] = '\0';
	return (res);
}
