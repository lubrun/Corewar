/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:50:10 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:52:31 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_buildstr(char const *s)
{
	char	*ptr;

	if (!(ptr = (char *)ft_strnew((size_t)ft_strlen((char *)s))))
		return (NULL);
	return (ptr = ft_strdup((char *)s));
}
