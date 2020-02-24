/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_printf.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 22:45:37 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 12:43:01 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

int		ft_malloc_liststr(const char *str, t_data *list, int index)
{
	if ((list->str = malloc(index + 1)) == NULL)
		return (0);
	ft_strncpy(list->str, str, index);
	list->len = index;
	return (1);
}

int		ft_read_printf(const char *str, t_data *list, va_list params)
{
	int index;

	index = 0;
	if (str[index] != '%')
	{
		while (str[index] != '%' && str[index] != '\0')
			index++;
		if (ft_malloc_liststr(str, list, index) == 0)
			return (-1);
	}
	else if (str[index] == '%' && str[index + 1] == '%')
	{
		index += 2;
		if (ft_malloc_liststr(str, list, 1) == 0)
			return (-1);
	}
	else if (str[index] == '%')
		index = ft_parse(&str[index + 1], list, params);
	if (str[index] == '\0')
		return (1);
	else
	{
		list->next = ft_datanew();
		return (ft_read_printf(&str[index], list->next, params));
	}
}
