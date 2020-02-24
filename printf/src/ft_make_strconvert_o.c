/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_o.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 19:15:16 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 15:04:35 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_octet(t_data *list, char *str_octet, char c)
{
	int len;

	ft_strcpy(list->str, str_octet);
	len = ft_strlen(list->str);
	if (list->precision > len)
		ft_strfadd(list->str, '0', (list->precision - len));
	else if (list->attribute[3] == '#')
		ft_strfadd(list->str, '0', 1);
	len = ft_strlen(list->str);
	if (list->width > len && list->attribute[2] == '-')
		ft_strnadd(&list->str[len], c, (list->width - len));
	else if (list->width > len && list->attribute[2] != '-')
		ft_strfadd(list->str, c, (list->width - len));
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

static int	ft_size(t_data *list, int len)
{
	int max_len;

	max_len = 0;
	if (len >= list->precision && len >= list->width)
		max_len = len + 1;
	else if (list->precision >= len && list->precision >= list->width)
		max_len = list->precision + 1;
	else
		max_len = list->width + 1;
	return (max_len);
}

int			ft_make_strconvert_o(t_data *list, va_list params)
{
	int				max_len;
	long long		decimal;
	char			*str_octet;
	int				len;
	char			c;

	c = (list->attribute[0] == '0' && list->precision < 0) ? '0' : ' ';
	decimal = va_arg(params, long long);
	ft_choose_mode(list, &decimal);
	str_octet = ft_ulltoa_base(decimal, 8);
	if ((list->precision == 0 && decimal == 0) ||
			(decimal == 0 && list->attribute[3] == '#'))
	{
		free(str_octet);
		str_octet = "";
	}
	len = ft_strlen(str_octet);
	max_len = ft_size(list, len);
	if ((list->str = (char*)malloc(sizeof(char*) * (max_len))) == NULL)
		return (-1);
	ft_octet(list, str_octet, c);
	if (len > 0)
		free(str_octet);
	return (1);
}
