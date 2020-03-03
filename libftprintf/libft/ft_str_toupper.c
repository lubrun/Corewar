/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:58:33 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:56:39 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_toupper(char **astr)
{
	char	*str;
	int		index;

	index = 0;
	if (*astr)
	{
		str = *astr;
		while (str[index])
		{
			if (ft_isalpha(str[index]) &&
				str[index] >= 'a' && str[index] <= 'z')
				str[index] -= 32;
			index++;
		}
	}
}
