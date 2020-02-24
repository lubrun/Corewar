/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_c.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 13:51:05 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 20:52:54 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_chara(t_data *list, char convert_c, char c)
{
	char tabc[2];

	tabc[0] = convert_c;
	tabc[1] = '\0';
	if (list->attribute[2] == '-' && list->width > 1)
	{
		ft_strnadd(list->str, c, list->width);
		list->str[0] = convert_c;
	}
	else if (list->attribute[2] != '-' && list->width > 1)
	{
		ft_strnadd(list->str, c, list->width);
		list->str[list->width - 1] = convert_c;
	}
	else
	{
		ft_strcpy(list->str, tabc);
	}
	return (1);
}

/*
** Size pour malloc
*/

static int	ft_size(int len, t_data *list)
{
	if (len >= list->precision && len >= list->width)
		return (len);
	else if (list->precision >= len && list->precision >= list->width)
		return (list->precision);
	return (list->width);
}

int			ft_make_strconvert_c(t_data *list, va_list params)
{
	int		max_len;
	char	convert_c;
	char	c;

	c = ' ';
	if (list->attribute[0] == '0')
		c = '0';
	convert_c = va_arg(params, int);
	if (list->precision == 0 && convert_c == 0)
		convert_c = '\0';
	max_len = ft_size(1, list) + 1;
	if ((list->str = (char*)malloc(sizeof(char*) * max_len)) == NULL)
		return (-1);
	ft_chara(list, convert_c, c);
	if (list->width > 1)
		list->len = list->width;
	else
		list->len = 1;
	return (1);
}
