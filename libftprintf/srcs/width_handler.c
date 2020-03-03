/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   width_handler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/03 17:51:05 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 13:51:47 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_null(t_conv **conv, char **atmp)
{
	char *tmp;

	tmp = *atmp;
	if ((*conv)->null_char && (*conv)->width > 0)
	{
		tmp = ft_strnew((*conv)->width);
		ft_memset(tmp, ' ', (*conv)->width);
		if ((*conv)->less_flag)
		{
			(*conv)->str = ft_strjoin((*conv)->str, tmp, 3);
			(*conv)->str[0] = '\0';
		}
		else
		{
			(*conv)->str = ft_strjoin(tmp, (*conv)->str, 3);
			(*conv)->str[ft_strlen((*conv)->str) - 1] = '\0';
		}
		(*conv)->str_len = (*conv)->width;
		return (1);
	}
	return (0);
}

void	check_f_flag(t_pars *expr, t_conv **aconv)
{
	t_conv	*conv;

	conv = *aconv;
	if (conv->type == 'f' && conv->prec_point &&
		get_precision(conv, expr->str) == 0)
	{
		if (conv->hashtag_flag)
		{
			conv->str = ft_strjoin(conv->float_value->left, ft_strdup("."), 2);
		}
		else if (conv->blank_flag)
		{
			conv->str = ft_strdup(conv->float_value->left);
			conv->str = ft_strjoin(ft_strdup(" "), conv->str, 3);
		}
		else
			conv->str = ft_strdup(conv->float_value->left);
		conv->str_len = ft_strlen(conv->str);
	}
}

void	apply_width(t_conv **conv, char **atmp)
{
	if (!(*conv)->less_flag)
	{
		if ((*conv)->zero_flag && (*conv)->precision == 0 &&
				!(*conv)->prec_point && !(*conv)->blank_flag)
			ft_memset(*atmp, '0', (*conv)->width - ft_strlen((*conv)->str));
		else if ((*conv)->zero_flag && (*conv)->precision == 0 &&
				!(*conv)->prec_point && (*conv)->blank_flag &&
				(*conv)->type != '%')
			ft_memset(*atmp, '0', (*conv)->width - ft_strlen((*conv)->str) - 1);
		else if (!(*conv)->blank_flag || ((*conv)->prec_point &&
					(*conv)->precision == 0))
			ft_memset(*atmp, ' ', (*conv)->width - ft_strlen((*conv)->str));
		else if ((*conv)->type != '%')
			ft_memset(*atmp, ' ', (*conv)->width - ft_strlen((*conv)->str) - 1);
		(*conv)->str = ft_strjoin(*atmp, (*conv)->str, 3);
	}
	else
	{
		if (!(*conv)->blank_flag || (*conv)->type == '%')
			ft_memset(*atmp, ' ', (*conv)->width - ft_strlen((*conv)->str));
		else if ((*conv)->type != '%')
			ft_memset(*atmp, ' ', (*conv)->width - ft_strlen((*conv)->str) - 1);
		(*conv)->str = ft_strjoin((*conv)->str, *atmp, 3);
	}
}

void	handle_width(t_pars **expr)
{
	char	*tmp;
	t_conv	*conv;

	conv = (*expr)->conv;
	if (check_null(&conv, &tmp) == 1)
		return ;
	check_f_flag(*expr, &conv);
	if (conv->width > (int)ft_strlen(conv->str))
	{
		if (conv->blank_flag)
			tmp = ft_strnew(conv->width - ft_strlen(conv->str) - 1);
		else
			tmp = ft_strnew(conv->width - ft_strlen(conv->str));
		if ((size_t)conv->width > ft_strlen(conv->str))
			apply_width(&conv, &tmp);
	}
	if (conv->type != '%')
		flags_width_handle(&conv);
	if (!conv->null_char)
		conv->str_len = ft_strlen(conv->str);
}
