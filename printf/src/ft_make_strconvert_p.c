/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_p.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 18:00:12 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:17:31 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_add_width_p(t_data *list, int len)
{
	char c;

	c = ' ';
	if (list->attribute[0] == '0')
		c = '0';
	if (list->attribute[2] == '-' && list->width > len)
		ft_strnadd(&list->str[len], c, (list->width - len));
	else if (list->width > len)
		ft_strfadd(list->str, c, (list->width - len));
	return (1);
}

static int	ft_pointer(t_data *list, char *convert_p)
{
	int		len;

	ft_strcpy(list->str, convert_p);
	if (list->precision > (len = ft_strlen(list->str)))
		ft_strfadd(list->str, '0', (list->precision - len));
	if (list->attribute[0] != '0')
	{
		ft_strfadd(list->str, 'x', 1);
		ft_strfadd(list->str, '0', 1);
		if (list->width > (len = ft_strlen(list->str)))
			ft_add_width_p(list, len);
	}
	else
	{
		if (list->width > ((len = ft_strlen(list->str)) + 2))
			ft_add_width_p(list, len);
		if (list->str[0] == '0' && list->str[1] == '0')
			list->str[1] = 'x';
		else
		{
			ft_strfadd(list->str, 'x', 1);
			ft_strfadd(list->str, '0', 1);
		}
	}
	return (1);
}

static int	ft_size(int len, t_data *list)
{
	if (len >= list->precision && len >= list->width)
		return (len);
	return (list->width);
}

int			ft_make_strconvert_p(t_data *list, va_list params)
{
	int		max_len;
	char	*convert_p;

	if (list->precision >= 0)
		list->attribute[0] = '\0';
	convert_p = ft_ulltoa_base(va_arg(params, unsigned long long), 16);
	if (convert_p[0] == '0' && list->precision == 0)
	{
		free(convert_p);
		convert_p = "";
	}
	max_len = ft_size((int)ft_strlen(convert_p), list);
	if ((list->str = (char*)malloc(sizeof(char*) * max_len)) == NULL)
		return (-1);
	ft_pointer(list, convert_p);
	list->len = ft_strlen(list->str);
	if (ft_strlen(convert_p) > 0)
		free(convert_p);
	return (1);
}
