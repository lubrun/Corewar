/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:24:15 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/25 14:49:11 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		swap_one(unsigned char *a, unsigned char *b)
{
	unsigned char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			swap_two(unsigned short int *swap)
{
	unsigned char	*new;

	new = (unsigned char *)swap;
	swap_one(new, new + 1);
}

void			swap_four(unsigned int *swap)
{
	unsigned char	*new;

	new = (unsigned char *)swap;
	swap_one(new, new + 3);
	swap_one(new + 1, new + 2);
}
