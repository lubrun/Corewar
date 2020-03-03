/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:17:58 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:56:19 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*rtn;

	if (!(rtn = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(rtn, ptr, size);
	free(ptr);
	ptr = NULL;
	return (rtn);
}
