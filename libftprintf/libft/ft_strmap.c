/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:07:04 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:58:14 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rtn;
	int		n;

	if (s == NULL)
		return (NULL);
	if (!(rtn = ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		rtn[n] = (*f)(s[n]);
		n++;
	}
	return (rtn);
}
