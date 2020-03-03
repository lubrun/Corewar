/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_prec_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:04:09 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:24 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			check_modifs(t_conv **conv, int value)
{
	if ((*conv)->hh_modif)
		value = (char)value;
	else if ((*conv)->h_modif)
		value = (short)value;
	(*conv)->ull_value = value;
}

static int		check_zero_value(t_conv **conv, int value)
{
	if ((*conv)->precision == 0 && (*conv)->prec_point && value == 0)
	{
		(*conv)->str = ft_strnew((*conv)->precision);
		flags_prec_handle(conv);
		return (1);
	}
	return (0);
}

static void		apply_prec(t_conv **conv, int value)
{
	(*conv)->str = ft_strnew((*conv)->precision);
	ft_memset((*conv)->str, '0', (*conv)->precision - ft_nbrlen(value, 10));
	if (value >= 0)
		(*conv)->str = ft_strjoin((*conv)->str, ft_lltoa_base(value, 10), 3);
	else if ((*conv)->width <= (*conv)->precision ||
			(*conv)->less_flag || (*conv)->is_neg)
	{
		(*conv)->str = ft_strjoin(ft_strdup("-"), (*conv)->str, 3);
		(*conv)->str = ft_strjoin((*conv)->str, ft_lltoa_base(value, 10), 3);
	}
}

void			put_value(t_conv **conv, int value)
{
	if (value < 0)
	{
		value *= -1;
		if (!(*conv)->zero_flag || ft_nbrlen(value, 10) >= (*conv)->width ||
			(*conv)->prec_point)
			(*conv)->str = ft_strjoin(ft_strdup("-"),
					ft_lltoa_base(value, 10), 3);
		else
			(*conv)->str = ft_lltoa_base(value, 10);
	}
	else
		(*conv)->str = ft_lltoa_base(value, 10);
}

void			d_prec_handle(t_conv **conv, int value)
{
	char	*str;

	str = NULL;
	check_modifs(conv, value);
	if (value < 0)
		(*conv)->is_neg = 1;
	if (check_zero_value(conv, value))
		return ;
	if ((*conv)->width && !(*conv)->prec_point && (*conv)->precision == 0 &&
			(*conv)->zero_flag
			&& value >= 0)
	{
		(*conv)->precision = (*conv)->width;
		(*conv)->width = 0;
	}
	if ((*conv)->precision > ft_nbrlen(value, 10))
		apply_prec(conv, value);
	else
		put_value(conv, value);
	flags_prec_handle(conv);
}
