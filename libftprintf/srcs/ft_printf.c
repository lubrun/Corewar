/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:34:27 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 11:15:15 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_conv(t_pars **alist, va_list vlist, int *count)
{
	conv_expr(alist, vlist);
	*count += (*alist)->conv->str_len;
	if ((*alist)->conv->null_char)
		write(1, (*alist)->conv->str, (*alist)->conv->str_len);
	else
		write(1, (*alist)->conv->str, (*alist)->conv->str_len);
	free_elem(*alist);
}

int		print(t_pars *list, va_list vlist)
{
	t_pars	*tmp;
	int		count;

	tmp = NULL;
	count = 0;
	while (list)
	{
		if (list->str != NULL)
		{
			tmp = list->next;
			if (ft_index(list->str, '%') != -1)
				print_conv(&list, vlist, &count);
			else
			{
				count += ft_strlen(list->str);
				write(1, list->str, ft_strlen(list->str));
				free_elem(list);
			}
		}
		list = tmp;
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list vlist;
	int		count;

	va_start(vlist, format);
	count = print(parse_arg((char *)format), vlist);
	va_end(vlist);
	return (count);
}
