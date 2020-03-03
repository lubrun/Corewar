/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 01:42:53 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:22 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		conv_expr(t_pars **expr, va_list vlist)
{
	handle_prec(expr, vlist);
	handle_width(expr);
	ft_strdel(&(*expr)->str);
	if (!(*expr)->conv->null_char)
		(*expr)->str = ft_strdup((*expr)->conv->str);
}

t_conv		*create_conv(void)
{
	t_conv *conv;

	conv = (t_conv *)ft_memalloc(sizeof(t_conv));
	conv->s_value = NULL;
	conv->str = NULL;
	conv->type = 0;
	conv->ull_value = 0;
	conv->str_len = 0;
	conv->precision = 0;
	conv->width = 0;
	conv->is_neg = 0;
	conv->prec_point = 0;
	conv->less_flag = 0;
	conv->zero_flag = 0;
	conv->plus_flag = 0;
	conv->blank_flag = 0;
	conv->hashtag_flag = 0;
	conv->big_l_modif = 0;
	conv->l_modif = 0;
	conv->h_modif = 0;
	conv->h_modif = 0;
	return (conv);
}
