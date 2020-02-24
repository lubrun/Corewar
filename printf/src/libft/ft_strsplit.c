/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:04:52 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:53:21 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_countletter(char *s, char c, char **tab, int index)
{
	int string;
	int len;
	int swap;

	string = 0;
	while (s[index])
	{
		len = 0;
		swap = index;
		while (s[index] == c && s[index])
			index++;
		if (s[index] != c && s[index])
		{
			while (s[index] != c && s[index])
			{
				index++;
				len++;
			}
			if (!(tab[string] = (char*)malloc(sizeof(char*) * len + 1)))
				return (0);
			ft_strpresplit(tab[string], &s[swap], c);
			string++;
		}
	}
	return (string);
}

char		**ft_strsplit(char const *s, char c)
{
	int		index;
	char	**tab;
	int		string;

	tab = NULL;
	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] != c && (!ft_isprint(s[index]) && s[index]))
			((unsigned char*)s)[index] = c;
		index++;
	}
	string = ft_countword((char*)s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * string + 1)))
		return (0);
	index = 0;
	string = ft_countletter((char*)s, c, tab, index);
	if (!(tab[string] = (char*)malloc(sizeof(char*) * 1)))
		return (0);
	tab[string] = NULL;
	return (tab);
}
