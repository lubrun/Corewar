/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:59:57 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:06:58 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(char *str)
{
	long long int	res;
	int				sign;

	res = 0;
	while (ft_is_whitespace(*str))
		str++;
	sign = (*str == '-' ? -1 : 1);
	*str == '-' || *str == '+' ? str++ : str;
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (res * sign);
}
