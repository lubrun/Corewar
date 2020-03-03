/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_d_prec_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:31:10 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:19 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_zero_value(t_conv **conv, long long value)
{
	if ((*conv)->precision == 0 && (*conv)->prec_point && value == 0)
	{
		(*conv)->str = ft_strnew((*conv)->precision);
		flags_prec_handle(conv);
		return (1);
	}
	return (0);
}

static void		apply_prec(t_conv **conv, long long value)
{
	(*conv)->str = ft_strnew((*conv)->precision);
	ft_memset((*conv)->str, '0', (*conv)->precision - ft_nbrlen(value, 10));
	if (value >= 0)
		(*conv)->str = ft_strjoin((*conv)->str,
				ft_lltoa_base(value, 10), 3);
	else if ((*conv)->width <= (*conv)->precision)
	{
		(*conv)->str = ft_strjoin(ft_strdup("-"),
				(*conv)->str, 3);
		(*conv)->str = ft_strjoin((*conv)->str,
				ft_lltoa_base(-value, 10), 3);
	}
}

void			big_d_prec_handle(t_conv **conv, long long value)
{
	char	*str;

	(*conv)->ull_value = value;
	str = NULL;
	if (value < 0)
		(*conv)->is_neg = 1;
	if (check_zero_value(conv, value))
		return ;
	if ((*conv)->precision > ft_nbrlen(value, 10))
		apply_prec(conv, value);
	else
	{
		if (value < 0)
			(*conv)->ull_value *= -1;
		(*conv)->str = ft_ulltoa_base((*conv)->ull_value, 10);
	}
	flags_prec_handle(conv);
}
