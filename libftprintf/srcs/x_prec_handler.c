/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_prec_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:43:45 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:47 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_zero_value(t_conv **conv, unsigned long long value)
{
	if ((*conv)->precision == 0 && (*conv)->prec_point && value == 0)
	{
		(*conv)->str = ft_strnew((*conv)->precision);
		flags_prec_handle(conv);
		return (1);
	}
	return (0);
}

void			check_plus_flag(t_conv **conv)
{
	if ((*conv)->plus_flag)
	{
		if (((!(*conv)->zero_flag && (*conv)->type != 'u')
			|| (((*conv)->zero_flag && ((*conv)->less_flag)) ||
			(*conv)->blank_flag)) && ft_index((*conv)->str, '-') == -1)
			(*conv)->str = ft_strjoin(ft_strdup("+"), (*conv)->str, 3);
	}
}

void			x_prec_handle(t_conv **conv, unsigned long long value)
{
	char	*str;

	str = NULL;
	(*conv)->ull_value = value;
	if (check_zero_value(conv, value) == 1)
		return ;
	if ((*conv)->precision > ft_nbrlen(value, 16))
	{
		(*conv)->str = ft_strnew((*conv)->precision);
		ft_memset((*conv)->str, '0', (*conv)->precision - ft_nbrlen(value, 16));
		(*conv)->str = ft_strjoin((*conv)->str, ft_ulltoa_base(value, 16), 3);
		if ((*conv)->hashtag_flag && value != 0)
			(*conv)->str = ft_strjoin(ft_strdup("0x"), (*conv)->str, 3);
	}
	else
	{
		(*conv)->str = ft_ulltoa_base(value, 16);
		if (((*conv)->hashtag_flag && value != 0 && ((*conv)->prec_point ||
			!(*conv)->zero_flag)) || (*conv)->type == 'p')
			(*conv)->str = ft_strjoin(ft_strdup("0x"), (*conv)->str, 3);
	}
	check_plus_flag(conv);
	if ((*conv)->type == 'X')
		ft_str_toupper(&((*conv)->str));
}
