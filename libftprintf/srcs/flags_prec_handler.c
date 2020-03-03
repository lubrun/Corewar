/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_prec_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 01:00:01 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:26 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_hashtag_prec(t_conv **conv)
{
	if ((*conv)->precision != 0 || (*conv)->width != 0)
		(*conv)->str = ft_strjoin(ft_strdup("0"), (*conv)->str, 3);
}

void	handle_is_neg_prec(t_conv **conv)
{
	if ((*conv)->width != 0 && (*conv)->precision == 0 &&
			!(*conv)->zero_flag && ft_index((*conv)->str, '-') == -1)
		(*conv)->str = ft_strjoin(ft_strdup("-"), (*conv)->str, 3);
}

void	handle_plus_prec(t_conv **conv)
{
	if (((!(*conv)->zero_flag)
		|| (((*conv)->zero_flag && ((*conv)->less_flag)) || (*conv)->blank_flag)
		|| ((*conv)->plus_flag && (*conv)->zero_flag && (*conv)->width != 0)) &&
		!(*conv)->is_neg)
		(*conv)->str = ft_strjoin(ft_strdup("+"), (*conv)->str, 3);
}

void	flags_prec_handle(t_conv **conv)
{
	if ((*conv)->is_neg)
		handle_is_neg_prec(conv);
	if ((*conv)->plus_flag && (*conv)->type != 'o' && (*conv)->type != 'O'
			&& (*conv)->type != 'u')
		handle_plus_prec(conv);
}
