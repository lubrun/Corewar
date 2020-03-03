/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_width_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:54:27 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:28 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_is_neg_width(t_conv **conv)
{
	if ((*conv)->width > (*conv)->precision &&
			ft_index((*conv)->str, '-') == -1)
		(*conv)->str[0] = '-';
	else
		(*conv)->str = ft_strjoin(ft_strdup("-"), (*conv)->str, 3);
}

void	handle_plus_less_width(t_conv **conv)
{
	if ((*conv)->plus_flag && !(*conv)->is_neg && (*conv)->zero_flag &&
		!(*conv)->less_flag && !(*conv)->blank_flag &&
		ft_index((*conv)->str, '+') == -1)
		(*conv)->str[0] = '+';
	if ((*conv)->less_flag && (*conv)->blank_flag)
		(*conv)->str = ft_strjoin(ft_strdup(" "), (*conv)->str, 3);
}

void	handle_blank_width(t_conv **conv)
{
	if (!(*conv)->plus_flag && !(*conv)->less_flag &&
			(*conv)->type != '%' && !(*conv)->is_neg)
		(*conv)->str = ft_strjoin(ft_strdup(" "), (*conv)->str, 3);
}

void	handle_hashtag_width(t_conv **conv)
{
	int		value;

	value = (*conv)->ull_value;
	if ((*conv)->zero_flag && value != 0 &&
			(*conv)->type == 'x' && ft_index((*conv)->str, 'x') == -1)
		(*conv)->str[1] = 'x';
	else if ((*conv)->zero_flag && value != 0 &&
			(*conv)->type == 'X' && ft_index((*conv)->str, 'X') == -1)
		(*conv)->str[1] = 'X';
}

void	flags_width_handle(t_conv **conv)
{
	if ((*conv)->plus_flag || (*conv)->less_flag)
		handle_plus_less_width(conv);
	if ((*conv)->blank_flag)
		handle_blank_width(conv);
	if ((*conv)->is_neg && ft_index((*conv)->str, '-') == -1)
		handle_is_neg_width(conv);
	if (((*conv)->type == 'x' || (*conv)->type == 'X') &&
			(*conv)->hashtag_flag)
		handle_hashtag_width(conv);
}
