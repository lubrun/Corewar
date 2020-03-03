/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 10:40:28 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:05:41 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		get_modifiers(t_pars *expr, t_conv **aconv)
{
	t_conv	*conv;
	int		index;

	conv = *aconv;
	index = 0;
	if (ft_index(expr->str, 'L') != -1)
		conv->big_l_modif = 1;
	if (ft_index(expr->str, 'l') != -1)
		conv->l_modif = 1;
	if ((index = ft_index(expr->str, 'h')) != -1)
	{
		if (ft_index(expr->str + index + 1, 'h') != -1)
			conv->hh_modif = 1;
		else
			conv->h_modif = 1;
	}
}

void		get_flags(t_pars *expr, t_conv **aconv)
{
	t_conv	*conv;

	conv = *aconv;
	if (ft_index(expr->str, '-') != -1)
		conv->less_flag = 1;
	if (ft_index(expr->str, '+') != -1)
		conv->plus_flag = 1;
	if (ft_index(expr->str, ' ') != -1)
		conv->blank_flag = 1;
	if (ft_index(expr->str, '#') != -1)
		conv->hashtag_flag = 1;
}

int			get_expr_len(const char *format)
{
	int		len;

	len = 0;
	if (format[len] == '%')
	{
		len++;
		while (ft_index(TYPES, format[len]) == -1)
			len++;
		return (len + 1);
	}
	else
	{
		while (format[len] && format[len] != '%')
			len++;
		return (len);
	}
}

t_pars		*parse_arg(char *format)
{
	int		index;
	int		expr_len;
	t_pars	*first;
	t_pars	*elem;
	char	*str;

	index = 0;
	expr_len = 0;
	first = NULL;
	str = NULL;
	if (ft_index(format, '%') == -1)
		return (create_elem(format));
	while ((size_t)index < ft_strlen(format))
	{
		expr_len = get_expr_len(format + index);
		str = ft_strsub((format + index), 0, expr_len);
		add_elem(&first, (elem = create_elem(str)));
		if (ft_index(elem->str, '%') != -1)
			parse_expr(&elem);
		index += expr_len;
		ft_strdel(&str);
	}
	return (first);
}

void		parse_expr(t_pars **expr)
{
	t_pars	*pars;
	t_conv	*conv;

	pars = *expr;
	pars->conv = create_conv();
	conv = pars->conv;
	conv->type = pars->str[ft_strlen(pars->str) - 1];
	conv->precision = get_precision(conv, pars->str);
	conv->width = get_width(pars->str);
	conv->zero_flag = get_zero_flag(pars->str);
	get_flags(pars, &conv);
	get_modifiers(pars, &conv);
}
