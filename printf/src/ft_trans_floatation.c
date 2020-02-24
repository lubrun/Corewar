/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trans_floatation.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 16:48:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 14:32:53 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

/*
**	concatene avant la virgule, le '.' et apres la virgule.
*/

static int		ft_make_strfloat(t_data *list, char *str_rest,
		char *str_double)
{
	int len;
	int len2;

	ft_strcpy(list->str, str_double);
	len = ft_strlen(list->str);
	if (list->precision > 0 || list->attribute[3] == '#')
		ft_strnadd(&list->str[len], '.', 1);
	if (list->precision > 0)
	{
		ft_strcat(list->str, str_rest);
		len2 = ft_strlen(list->str);
		if (len2 < (len + 1 + list->precision))
		{
			ft_strnadd(&list->str[len2], '0',
					((len + 1 + list->precision) - len2));
		}
	}
	return (1);
}

/*
**	malloc list->str.
*/

static char		*ft_float_decimal(char *str_double, char *str_rest,
		t_data *list)
{
	int			max_len;

	if (list->width >
			(max_len = (ft_strlen(str_double) + ft_strlen(str_rest) + 1)))
		max_len = list->width;
	if ((list->str = (char*)malloc(sizeof(char*) * (max_len + 1))) == NULL)
		return (NULL);
	return (str_rest);
}

/*
**	recupere en *char apres la virgule.
*/

static char		*ft_make_tab_rest(t_data *list, char *str_rest,
		long double rest)
{
	int			count;
	long double	tmp;
	int			index;

	index = 0;
	count = -1;
	tmp = rest;
	while (++count <= list->precision)
		rest = rest * 10;
	if ((str_rest = malloc(sizeof(int) * (list->precision + 1))) == NULL)
		return (0);
	count = -1;
	while (++count <= list->precision)
	{
		tmp = tmp * 10;
		str_rest[index++] = ((long)tmp % 10) + '0';
		tmp = tmp - (long)tmp;
	}
	str_rest[index] = '\0';
	return (str_rest);
}

/*
**	arrondir au supperieur si => 5.
*/

static int		ft_round(char *str, int end)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	if (str[--index] >= '5')
	{
		if (--index == -1)
			return (1);
		while (str[index] == '9' && index > 0)
			str[index--] = '0';
		if (str[index] < '9')
			str[index] = str[index] + 1;
		else if (index == 0 && str[index] == '9')
		{
			str[index] = '0';
			str[end] = '\0';
			return (1);
		}
		str[end] = '\0';
	}
	else
		str[index] = '\0';
	return (0);
}

/*
**	but concatene avant et apres la virgule.
*/

char			*ft_trans_floatation(t_data *list, long double decimal)
{
	long double	rest;
	char		*str_rest;
	char		*str_double;
	int			index;

	index = 0;
	str_rest = NULL;
	if (list->precision < 0)
		list->precision = 6;
	str_double = ft_ulltoa_base(decimal, 10);
	if (decimal > 9223372036854775807)
		rest = decimal - 9223372036854775807;
	else
		rest = decimal == 0 ? 0 : (decimal - ft_atol(str_double));
	str_rest = ft_make_tab_rest(list, str_rest, rest);
	if (ft_round(str_rest, list->precision) == 1)
		str_double = ft_ulltoa_base(decimal + 1, 10);
	ft_float_decimal(str_double, str_rest, list);
	ft_make_strfloat(list, str_rest, str_double);
	if (ft_strlen(str_rest) > 0)
		free(str_rest);
	if (ft_strlen(str_double) > 0)
		free(str_double);
	return (list->str);
}
