/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_u.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 21:20:18 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 13:05:23 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_unsigned(t_data *list, char *str_unsigned)
{
	int		len;
	char	c;

	c = ' ';
	if (list->attribute[0] == '0' && list->precision < 0)
		c = '0';
	ft_strcpy(list->str, str_unsigned);
	if (list->precision > (len = ft_strlen(list->str)))
		ft_strfadd(list->str, '0', (list->precision - len));
	if (list->attribute[2] == '-' && list->width > (len = ft_strlen(list->str)))
		ft_strnadd(&list->str[len], c, (list->width - len));
	else if (list->width > (len = ft_strlen(list->str)))
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

int			ft_make_strconvert_u(t_data *list, va_list params)
{
	int				max_len;
	long long		decimal;
	char			*str_unsigned;
	int				len;

	decimal = va_arg(params, long long);
	ft_choose_mode(list, &decimal);
	str_unsigned = ft_ulltoa_base((unsigned long long)decimal, 10);
	if (list->precision == 0 && decimal == 0)
		str_unsigned = "";
	len = ft_strlen(str_unsigned);
	if (len >= list->precision && len >= list->width)
		max_len = len + 1;
	else if (list->precision >= len && list->precision >= list->width)
		max_len = list->precision + 1;
	else
		max_len = list->width + 1;
	if ((list->str = (char*)malloc(sizeof(char*) * max_len)) == NULL)
		return (-1);
	ft_unsigned(list, str_unsigned);
	if (ft_strlen(str_unsigned) > 0)
		free(str_unsigned);
	return (1);
}
