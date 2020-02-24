/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_x.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 17:24:38 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 15:02:17 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_hexazero(t_data *list, char *str_hexa, char c, int decimal)
{
	ft_strnadd(list->str, c, list->width);
	ft_str_endcpy(list->str, str_hexa);
	if (list->attribute[3] == '#' && list->str[1] == '0' && decimal != 0)
	{
		list->str[0] = '0';
		list->str[1] = 'x';
	}
	else if (list->attribute[3] == '#' && decimal != 0)
	{
		ft_strfadd(list->str, 'x', 1);
		ft_strfadd(list->str, '0', 1);
	}
	return (1);
}

static int	ft_hexa(t_data *list, char *str_hexa, char c, int decimal)
{
	int len;

	if (c == '0')
		ft_hexazero(list, str_hexa, c, decimal);
	else
	{
		ft_strcpy(list->str, str_hexa);
		len = ft_strlen(list->str);
		if (list->precision > len)
			ft_strfadd(list->str, '0', list->precision - len);
		if (list->attribute[3] == '#' && decimal != 0)
		{
			ft_strfadd(list->str, 'x', 1);
			ft_strfadd(list->str, '0', 1);
		}
		len = ft_strlen(list->str);
		if (list->attribute[2] == '-' && list->width > len)
			ft_strnadd(&list->str[len], c, (list->width - len));
		else if (list->width > len)
			ft_strfadd(list->str, c, (list->width - len));
	}
	if (list->convert == 'X')
		ft_strupcase(list->str);
	list->len = ft_strlen(list->str);
	return (1);
}

static void	ft_choose_mode(t_data *list, long long *decimal)
{
	if (list->mode[0] == 'h' && list->mode[1] == 'h')
		*decimal = (unsigned char)*decimal;
	else if (list->mode[0] == 'h')
		*decimal = (unsigned short int)*decimal;
	else if (list->mode[0] == 'l' && list->mode[1] == 'l')
		*decimal = (unsigned long long int)*decimal;
	else if (list->mode[0] == 'l')
		*decimal = (unsigned long int)*decimal;
	else
		*decimal = (unsigned int)*decimal;
}

int			ft_make_strconvert_x(t_data *list, va_list params)
{
	int				max_len;
	long long		decimal;
	char			*str_hexa;
	int				len;
	char			c;

	c = (list->attribute[0] == '0' && list->precision < 0) ? '0' : ' ';
	decimal = va_arg(params, long long);
	ft_choose_mode(list, &decimal);
	str_hexa = ft_ulltoa_base(decimal, 16);
	if (list->precision == 0 && decimal == 0)
		str_hexa = "";
	len = ft_strlen(str_hexa);
	if (len >= list->precision && len >= list->width)
		max_len = len + 2;
	else if (list->precision >= len && list->precision >= list->width)
		max_len = list->precision + 2;
	else
		max_len = list->width + 2;
	if ((list->str = (char*)malloc(sizeof(char*) * (max_len))) == NULL)
		return (-1);
	ft_hexa(list, str_hexa, c, decimal);
	if (ft_strlen(str_hexa) > 0)
		free(str_hexa);
	return (1);
}
