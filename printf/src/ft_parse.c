/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 11:19:39 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 12:12:23 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** Precision avec rajout d'un '\0' pour ne pas deborder.
*/

int		ft_mode(const char *str, t_data *list, int start, int letter)
{
	int index;

	index = 0;
	if (str[index] == 'h')
	{
		list->mode[letter] = 'h';
		index++;
		if (str[index] == 'h')
			list->mode[++letter] = 'h';
	}
	else if (str[index] == 'l')
	{
		list->mode[letter] = 'l';
		index++;
		if (str[index] == 'l')
			list->mode[++letter] = 'l';
	}
	else if (str[index] == 'L')
	{
		index++;
		list->mode[letter] = 'L';
	}
	list->mode[letter + 1] = '\0';
	return (index + start + letter);
}

/*
** Precision.
*/

int		ft_precision(const char *str, t_data *list, int start, va_list params)
{
	int index;

	index = 0;
	if (str[index] == '*')
	{
		list->precision = va_arg(params, int);
		index++;
	}
	else
	{
		list->precision = 0;
		while (str[index] >= '0' && str[index] <= '9')
			index++;
		list->precision = ft_atoi(str);
	}
	return (index + start);
}

/*
** Largeur. Si * largeur = 1er argument.
*/

int		ft_width(const char *str, t_data *list, int start, va_list params)
{
	int index;

	index = 0;
	if (str[index] == '*')
	{
		list->asterix = '*';
		list->width = va_arg(params, int);
		if (list->width < 0)
		{
			list->attribute[2] = '-';
			list->width = -list->width;
		}
		index++;
	}
	else
	{
		while (str[index] >= '0' && str[index] <= '9')
		{
			index++;
		}
		list->width = ft_atoi(str);
	}
	return (index + start);
}

/*
** save attribute |0:0| |1:+| |2:-| |3:#| |4:space|
*/

int		ft_attribute(const char *str, t_data *list, int start)
{
	int index;

	index = 0;
	while (ft_is_attribute(str[index]))
	{
		if (str[index] == '0')
			list->attribute[0] = '0';
		if (str[index] == '+')
			list->attribute[1] = '+';
		if (str[index] == '-')
			list->attribute[2] = '-';
		if (str[index] == '#')
			list->attribute[3] = '#';
		if (str[index] == ' ')
			list->attribute[4] = ' ';
		index++;
	}
	return (index + start);
}

/*
** Save les modulation du printf dans la struct puis fait la str
*/

int		ft_parse(const char *str, t_data *list, va_list params)
{
	int		index;

	index = 0;
	if ((list->convert = ft_str_isconvert(str)) == 0)
		return (1);
	index = ft_attribute(&str[index], list, index);
	index = ft_width(&str[index], list, index, params);
	if (str[index] == '.')
		index = ft_precision(&str[index + 1], list, index + 1, params);
	index = ft_mode(&str[index], list, index, 0);
	if (list->attribute[2] == '-')
		list->attribute[0] = '\0';
	if (str[index] == list->convert)
	{
		ft_choose_params(list, params);
		return (index + 2);
	}
	return (1);
}
