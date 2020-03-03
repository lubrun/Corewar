/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   u_prec_handler.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/21 15:47:48 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 11:18:17 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_zero_value(t_conv **conv, unsigned long long value)
{
	if ((*conv)->precision == 0 && (*conv)->prec_point && value == 0 &&
		!(*conv)->hashtag_flag)
	{
		(*conv)->str = ft_strnew((*conv)->precision);
		flags_prec_handle(conv);
		return (1);
	}
	return (0);
}

static void		apply_prec(t_conv **conv, unsigned long long value, int base)
{
	(*conv)->hashtag_flag = 0;
	(*conv)->str = ft_strnew((*conv)->precision - ft_nbrlen(value, base));
	if ((*conv)->prec_point && (*conv)->precision == 0)
		ft_memset((*conv)->str, ' ', (*conv)->precision -
				ft_nbrlen(value, base));
	else if ((*conv)->precision != 0 && (*conv)->hashtag_flag)
		ft_memset((*conv)->str, '0', (*conv)->precision -
				ft_nbrlen(value, base));
	else if ((*conv)->precision != 0 && !(*conv)->hashtag_flag)
		ft_memset((*conv)->str, '0', (*conv)->precision -
				ft_nbrlen(value, base));
	(*conv)->str = ft_strjoin((*conv)->str, ft_ulltoa_base(value, base), 1);
}

void			u_prec_handle(t_conv **conv, unsigned long long value)
{
	char	*str;
	int		base;

	(*conv)->ull_value = value;
	str = NULL;
	if ((*conv)->type == 'o' || (*conv)->type == 'O')
		base = 8;
	else
		base = 10;
	if (check_zero_value(conv, value))
		return ;
	if ((*conv)->precision > ft_unbrlen(value, base))
		apply_prec(conv, value, base);
	else
		(*conv)->str = ft_ulltoa_base(value, base);
	flags_prec_handle(conv);
	if (base == 8 && (*conv)->hashtag_flag
			&& value != 0)
		(*conv)->str = ft_strjoin(ft_strdup("0"), (*conv)->str, 3);
}
