/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:57:12 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:35:25 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_countword(const char *src, const char *c)
{
	int		i;
	int		cword;

	i = 0;
	cword = 0;
	while (src[i])
	{
		if (ft_strchr(c, src[i]))
			i++;
		if (src[i] && !ft_strchr(c, src[i]))
		{
			cword++;
			while (src[i] && !ft_strchr(c, src[i]))
				i++;
		}
	}
	return (cword);
}

static char	*ft_getnextword(const char *s, const char *c)
{
	char	*dst;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (!ft_strchr(c, s[i]) && s[i])
	{
		len++;
		i++;
	}
	if (!(dst = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[len] = '\0';
	i = 0;
	while (!ft_strchr(c, s[i]) && s[i])
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}

char		**ft_strsplit(const char *s, char *c)
{
	char	**split;
	int		is;
	int		i;

	if (!s || !c)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		return (NULL);
	is = 0;
	i = 0;
	while (*s)
	{
		if (*s && ft_strchr(c, *s))
			s++;
		if (*s && !ft_strchr(c, *s))
		{
			split[is++] = ft_getnextword(s, c);
			while (*s && !ft_strchr(c, *s))
				s++;
		}
	}
	split[is] = NULL;
	return (split);
}
