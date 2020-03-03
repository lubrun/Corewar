/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:39:14 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:57:23 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *str, void (*f)(char *))
{
	int		n;

	if (str == NULL || f == NULL)
		return ;
	n = 0;
	while (str[n] != '\0')
	{
		(*f)(&str[n]);
		n++;
	}
}
