/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_d.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:46:04 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:06:02 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static char	ft_signe(t_data *list, int negative)
{
	char signe;

	signe = '\0';
	if (negative == -1)
		signe = '-';
	else if (list->attribute[1] == '+')
		signe = '+';
	else if (list->attribute[4] == ' ')
		signe = ' ';
	return (signe);
}

static void	ft_decimal(t_data *list, char *str_decimal, int negative, char c)
{
	int		len;
	char	signe;

	signe = ft_signe(list, negative);
	ft_strcpy(list->str, str_decimal);
	if (list->precision > (len = ft_strlen(list->str)))
		ft_strfadd(list->str, '0', (list->precision - len));
	if (list->attribute[2] == '-' && signe != '\0')
		ft_strfadd(list->str, signe, 1);
	signe = list->attribute[2] == '-' ? '\0' : signe;
	if (list->width > (len = ft_strlen(list->str)) && list->attribute[2] == '-')
		ft_strnadd(&list->str[len], c, (list->width - len));
	else if (list->width > (len = ft_strlen(list->str)))
		ft_strfadd(list->str, c, (list->width - len));
	if (list->width > list->precision && list->width >
			(int)ft_strlen(str_decimal))
	{
		if (signe != '\0' && list->attribute[0] != '0')
			list->str[(list->width - len - 1)] = signe;
		else if (signe != '\0')
			list->str[0] = signe;
	}
	else if (signe != '\0')
		ft_strfadd(list->str, signe, 1);
	list->len = ft_strlen(list->str);
}

static void	ft_choose_mode(t_data *list, long long *decimal)
{
	if (list->attribute[2] == '-' || list->precision >= 0)
		list->attribute[0] = '\0';
	if (list->mode[0] == 'h' && list->mode[1] == 'h')
		*decimal = (char)*decimal;
	else if (list->mode[0] == 'h')
		*decimal = (short int)*decimal;
	else if (list->mode[0] == 'l' && list->mode[1] == 'l')
		*decimal = (long long int)*decimal;
	else if (list->mode[0] == 'l')
		*decimal = (long int)*decimal;
	else
		*decimal = (int)*decimal;
}

/*
** Recupere l'argument et le stock dans struct.str
*/

static int	ft_size(t_data *list, int len)
{
	int max_len;

	max_len = 0;
	if (len >= list->precision && len >= list->width)
		max_len = len;
	else if (list->precision >= len && list->precision >= list->width)
		max_len = list->precision;
	else
		max_len = list->width;
	return (max_len);
}

int			ft_make_strconvert_d(t_data *list, va_list params)
{
	int				max_len;
	long long		decimal;
	char			*str_decimal;
	int				negative;
	char			c;

	decimal = va_arg(params, long long);
	ft_choose_mode(list, &decimal);
	negative = (decimal < 0) ? -1 : 0;
	decimal = (negative == -1) ? -decimal : decimal;
	str_decimal = ft_ulltoa_base((unsigned long long)decimal, 10);
	if (list->precision == 0 && decimal == 0)
	{
		free(str_decimal);
		str_decimal = "";
	}
	max_len = ft_size(list, ft_strlen(str_decimal));
	if ((list->str = (char*)malloc(sizeof(char*) * (max_len + 1))) == NULL)
		return (-1);
	c = (list->attribute[0] == '0') ? '0' : ' ';
	ft_decimal(list, str_decimal, negative, c);
	if (ft_strlen(str_decimal) > 0)
		free(str_decimal);
	return (1);
}
