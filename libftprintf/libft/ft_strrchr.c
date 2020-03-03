/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:15:05 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:59:03 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;

	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (last != -1)
		return ((char *)s + last);
	else if ((int)s[i] == c)
		return ((char *)s + i);
	else
		return (NULL);
}
