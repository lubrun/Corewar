/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_s.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 16:51:45 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 20:54:55 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_string(t_data *list, char *convert_s, char c)
{
	int len;

	if (list->precision >= 0)
		ft_strncpy(list->str, convert_s, list->precision);
	else
		ft_strcpy(list->str, convert_s);
	len = ft_strlen(list->str);
	if (list->attribute[2] == '-' && list->width > len)
		ft_strnadd(&list->str[len], c, (list->width - len));
	else if (list->width > len)
		ft_strfadd(list->str, c, (list->width - len));
	return (1);
}

static int	ft_size(int len, t_data *list)
{
	if (len >= list->precision && len >= list->width)
		return (len);
	else if (list->precision >= len && list->precision >= list->width)
		return (list->precision);
	return (list->width);
}

int			ft_make_strconvert_s(t_data *list, va_list params)
{
	int		max_len;
	char	*convert_s;
	char	c;

	c = ' ';
	if (list->attribute[0] == '0')
		c = '0';
	convert_s = va_arg(params, char*);
	if (convert_s == NULL)
		convert_s = "(null)";
	max_len = ft_size(ft_strlen(convert_s), list);
	if ((list->str = (char*)malloc(sizeof(char*) * max_len)) == NULL)
		return (-1);
	ft_string(list, convert_s, c);
	list->len = ft_strlen(list->str);
	return (1);
}
