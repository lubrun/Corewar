/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:12:54 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:55:10 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, void const *s2, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	ptr2 = (unsigned char *)s2;
	ptr1 = (unsigned char *)s1;
	i = 0;
	while (i < (int)n)
	{
		if (ptr2[i] == (unsigned char)c)
		{
			ptr1[i] = (unsigned char)ptr2[i];
			i++;
			return ((unsigned char *)ptr1 + i);
		}
		else
		{
			ptr1[i] = (unsigned char)ptr2[i];
			i++;
		}
	}
	return (NULL);
}
