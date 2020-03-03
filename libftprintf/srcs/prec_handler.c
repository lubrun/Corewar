/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:10:19 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:38 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	s_prec_handle(t_conv **conv, char *value)
{
	if (value == NULL)
	{
		(*conv)->str = ft_strdup("(null)");
		(*conv)->s_value = ft_strdup((*conv)->str);
	}
	else
	{
		(*conv)->str = ft_strdup(value);
		(*conv)->s_value = ft_strdup(value);
	}
	if ((*conv)->precision != 0 || (*conv)->prec_point)
		(*conv)->str = ft_strsub((*conv)->str, 0, (*conv)->precision);
	if ((*conv)->width != 0 && (*conv)->zero_flag && !(*conv)->less_flag)
	{
		(*conv)->str = ft_strnew((*conv)->width);
		ft_memset((*conv)->str, '0', (*conv)->width);
	}
}

void	f_prec_handle(t_conv **conv, long double value)
{
	t_float	*flt;
	char	*tmp;

	if ((*conv)->precision == 0)
		(*conv)->precision = 6;
	(*conv)->float_value = new_float(value, (*conv)->precision);
	flt = (*conv)->float_value;
	(*conv)->str = ft_strjoin(flt->left, ft_strdup("."), 2);
	(*conv)->str = ft_strjoin((*conv)->str, flt->right, 1);
	if ((int)ft_strlen(flt->right) < (*conv)->precision)
	{
		tmp = ft_strnew(((*conv)->precision - ft_strlen(flt->right)));
		ft_memset(tmp, '0', ((*conv)->precision - ft_strlen(flt->right) - 1));
		(*conv)->str = ft_strjoin((*conv)->str, tmp, 3);
	}
	if ((*conv)->blank_flag)
		(*conv)->str = ft_strjoin(ft_strdup(" "), (*conv)->str, 3);
	if (flt->sign)
		(*conv)->str = ft_strjoin(ft_strdup("-"), (*conv)->str, 3);
}

void	c_prec_handle(t_conv **aconv, char c)
{
	t_conv		*conv;

	conv = *aconv;
	conv->str = ft_strnew(1);
	conv->str[0] = c;
	if (conv->str[0] == '\0')
		conv->null_char = 1;
	conv->str_len = 1;
}

void	handle_prec_2(t_pars **expr, va_list vlist)
{
	t_conv	*conv;
	char	type;

	conv = (*expr)->conv;
	type = conv->type;
	if (type == 'c' || type == '%')
		c_prec_handle(&conv, (type == 'c') ? va_arg(vlist, int) : '%');
	else if (type == 's')
		s_prec_handle(&conv, va_arg(vlist, char*));
	else if (type == 'x' || type == 'X')
		x_prec_handle(&conv, va_arg(vlist, unsigned long long));
	else if (type == 'p')
		x_prec_handle(&conv, (unsigned long long)va_arg(vlist, void *));
	else if (type == 'f')
	{
		if (conv->big_l_modif)
			f_prec_handle(&conv, va_arg(vlist, long double));
		else
			f_prec_handle(&conv, (long double)va_arg(vlist, double));
	}
	else
		conv->str = ft_fillnewstr((size_t)1, conv->type);
}

void	handle_prec(t_pars **expr, va_list vlist)
{
	t_conv	*conv;
	char	type;

	conv = (*expr)->conv;
	type = conv->type;
	if (type == 'd' || type == 'i' || type == 'D')
	{
		if (!conv->l_modif && type != 'D')
			d_prec_handle(&conv, va_arg(vlist, int));
		else if (conv->l_modif || type == 'D')
			big_d_prec_handle(&conv, va_arg(vlist, long long));
	}
	else if (type == 'u' || type == 'U' ||
			type == 'o' || type == 'O')
	{
		if (!conv->h_modif && !conv->hh_modif)
			u_prec_handle(&conv, va_arg(vlist, unsigned long long));
		else if (conv->h_modif)
			u_prec_handle(&conv, (unsigned short)va_arg(vlist, unsigned int));
		else if (conv->hh_modif)
			u_prec_handle(&conv, (unsigned char)va_arg(vlist, unsigned int));
	}
	else
		handle_prec_2(expr, vlist);
}
