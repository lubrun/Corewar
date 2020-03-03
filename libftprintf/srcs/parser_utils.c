/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:37:25 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:33 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_zero_flag(char *str)
{
	int		index;

	index = 0;
	while (str[index] && !ft_isdigit(str[index]) &&
			str[index] != '.')
		index++;
	if (str[index] == '0')
		return (1);
	return (0);
}

int		get_width(char *str)
{
	int		index;

	index = 0;
	while (str[index] && (!ft_isdigit(str[index]) || str[index] == '0') &&
			str[index] != '.')
		index++;
	return (ft_atoi(str + index));
}

int		get_precision(t_conv *conv, char *str)
{
	int		index;

	index = 0;
	if (ft_index(str, '.') != -1)
		conv->prec_point = 1;
	if ((index = ft_index(str, '.')) != -1)
		return (ft_atoi(str + index + 1));
	return (0);
}
