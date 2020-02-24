/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_f.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 12:48:00 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 13:40:47 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_float(t_data *list, int negative, char c, char signe)
{
	int len;

	len = ft_strlen(list->str);
	if (list->width > len && list->attribute[2] != '-')
		ft_strfadd(list->str, c, (list->width - len));
	else if (list->width > len)
		ft_strnadd(&list->str[len], ' ', (list->width - len));
	if (negative == -1)
		signe = '-';
	else if (list->attribute[1] == '+')
		signe = '+';
	else if (list->attribute[4] == ' ')
		signe = ' ';
	if (signe != '\0' && list->attribute[0] == '0')
	{
		if (list->str[0] == '0' && list->str[1] != '.')
			list->str[0] = signe;
		else
			ft_strfadd(list->str, signe, 1);
	}
	list->len = ft_strlen(list->str);
}

static void	ft_choose_mode(t_data *list, long double *decimal, va_list params)
{
	if (list->mode[0] == 'L')
		*decimal = va_arg(params, long double);
	else if (list->mode[0] == 'l')
		*decimal = va_arg(params, long double);
	else
		*decimal = va_arg(params, double);
}

int			ft_make_strconvert_f(t_data *list, va_list params)
{
	long double	decimal;
	char		c;
	int			negative;
	char		signe;

	signe = '\0';
	c = '0';
	ft_choose_mode(list, &decimal, params);
	negative = (decimal < 0) ? -1 : 1;
	decimal = (decimal < 0) ? -decimal : decimal;
	ft_trans_floatation(list, decimal);
	if (negative == -1)
		signe = '-';
	else if (list->attribute[1] == '+')
		signe = '+';
	else if (list->attribute[4] == ' ')
		signe = ' ';
	if (list->attribute[0] != '0')
	{
		c = ' ';
		if (signe != '\0')
			ft_strfadd(list->str, signe, 1);
	}
	ft_float(list, negative, c, signe);
	return (1);
}
