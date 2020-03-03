/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:53:22 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:55:31 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long nbr, int base)
{
	int		len;

	len = 0;
	if (nbr < -9223372036854775807)
		return (20);
	if (nbr < 0)
		return (ft_nbrlen(nbr * -1, base));
	if (nbr == 0)
		return (1);
	while (nbr >= base)
	{
		len++;
		nbr /= base;
	}
	if (nbr > 0)
		len++;
	return (len);
}
