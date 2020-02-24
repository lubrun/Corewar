/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_choose_params.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 12:32:59 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 12:33:03 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** Lance la conversion en fonction du %.
*/

int		ft_choose_params(t_data *list, va_list params)
{
	if (list->convert == 'd' || list->convert == 'i')
		return (ft_make_strconvert_d(list, params));
	else if (list->convert == 'c')
		return (ft_make_strconvert_c(list, params));
	else if (list->convert == 'p')
		return (ft_make_strconvert_p(list, params));
	else if (list->convert == 's')
		return (ft_make_strconvert_s(list, params));
	else if (list->convert == 'x' || list->convert == 'X')
		return (ft_make_strconvert_x(list, params));
	else if (list->convert == 'o')
		return (ft_make_strconvert_o(list, params));
	else if (list->convert == '%')
		return (ft_make_strconvert_pc(list));
	else if (list->convert == 'u')
		return (ft_make_strconvert_u(list, params));
	else if (list->convert == 'f')
		return (ft_make_strconvert_f(list, params));
	return (0);
}
