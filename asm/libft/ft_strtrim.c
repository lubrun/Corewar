/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:08:47 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 12:57:32 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloclen(char const *s, int index, int j)
{
	int		len;
	char	*res;
	res = NULL;
	len = 0;
	while (s[index])
		index++;
	while (s[index - 1] == ' ' || s[index - 1] == '\t' || s[index - 1] == '\n')
	{
		len++;
		index--;
	}
	len = ft_strlen((char*)s) - len - j;
	if (!(res = (char*)malloc(sizeof(char) * (len) + (1))))
		return (NULL);
	len = 0;
	while ((j + len) < index)
	{
		res[len] = s[j + len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
char		*ft_strtrim(char const *s)
{
	int		index;
	int		j;
	char	*res;
	res = NULL;
	j = 0;
	index = 0;
	if (!s)
		return (0);
	while ((s[index] == ' ' || s[index] == '\t' || s[index] == '\n'))
		index++;
	j = index;
	if (s[index] == '\0')
	{
		if (!(res = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	return (ft_malloclen(s, index, j));
}