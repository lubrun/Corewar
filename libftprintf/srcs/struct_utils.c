/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:54:56 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:48:40 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		round_flt(long double value, int precision, t_float *flt)
{
	unsigned long long	left;
	unsigned long long	right;
	int					index;

	index = 0;
	if (value - (int)value > 0.1)
	{
		left = ft_atoull(flt->left);
		right = ft_atoull(flt->right);
		if (ft_nbrlen(right + 1, 10) > precision)
		{
			left++;
			ft_strdel(&flt->right);
			flt->right = ft_fillnewstr((int)precision, '0');
		}
		else if ((value - (int)value) * 10 > 5)
		{
			right++;
			ft_strdel(&flt->right);
			flt->right = ft_ulltoa_base(right, 10);
		}
		ft_strdel(&flt->left);
		flt->left = ft_ulltoa_base(left, 10);
	}
}

t_float		*new_float(long double value, int precision)
{
	t_float				*flt;
	int					index;
	unsigned long long	right;

	index = 0;
	right = 0;
	flt = ft_memalloc(sizeof(t_float));
	flt->left = ft_ulltoa_base((unsigned long long)value, 10);
	flt->sign = 0;
	if (value < 0)
	{
		flt->sign++;
		value *= -1;
	}
	flt->right = ft_strnew(precision);
	while (value > 0.0 && index < precision)
	{
		value -= (int)value;
		value *= 10;
		flt->right[index] = (int)value + '0';
		index++;
	}
	right = ft_atoull(flt->right);
	round_flt(value, precision, flt);
	return (flt);
}

t_pars		*create_elem(char *str)
{
	t_pars *elem;

	if (!(elem = (t_pars *)ft_memalloc(sizeof(t_pars))))
		return (NULL);
	elem->str = ft_strdup(str);
	elem->next = NULL;
	return (elem);
}

void		add_elem(t_pars **alist, t_pars *elem)
{
	t_pars *tmp;

	if (*alist == NULL)
	{
		*alist = elem;
	}
	else
	{
		tmp = *alist;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

void		free_elem(t_pars *pars)
{
	t_conv	*conv;

	conv = pars->conv;
	if (conv && conv->float_value != NULL)
	{
		ft_strdel(&(conv->float_value->right));
		ft_strdel(&(conv->float_value->left));
		free(conv->float_value);
	}
	ft_strdel(&(pars->str));
	if (conv)
	{
		ft_strdel(&(conv->s_value));
		ft_strdel(&(conv->str));
		free(conv);
	}
	free(pars);
}
