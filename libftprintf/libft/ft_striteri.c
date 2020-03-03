/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:51:28 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:57:28 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	n;

	if (str == NULL || f == NULL)
		return ;
	n = 0;
	while (str[n] != '\0')
	{
		(*f)(n, &str[n]);
		n++;
	}
}
