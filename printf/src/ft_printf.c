/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 11:23:17 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 19:17:03 by qbarrier         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"
#include <stdio.h>

static int	ft_display_printf(t_data *list)
{
	int res;
	int index;

	index = 0;
	res = 0;
	while (list)
	{
		if (list->convert == 'c')
		{
			while (index < list->len)
			{
				ft_putchar(list->str[index]);
				index++;
			}
			index = 0;
		}
		else
		{
			ft_putstr(list->str);
		}
		res += list->len;
		list = list->next;
	}
	return (res);
}

void		f_test_va(t_data *list, va_list va)
{
	int	n;

	while (list)
	{
		n = va_arg(va, int);
		ft_putnbr(n);
		list = list->next;
	}
}

int			ft_printf(const char *format, ...)
{
	t_data		*list;
	va_list		params;
	int			res;

	res = 0;
	list = NULL;
	list = ft_datanew();
	va_start(params, format);
	if (ft_read_printf(format, list, params) < 0)
	{
		ft_lstdel_str(list);
		return (-1);
	}
	res = ft_display_printf(list);
	ft_lstdel_str(list);
	va_end(params);
	return (res);
}
