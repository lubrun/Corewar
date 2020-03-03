/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 01:13:31 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:54:33 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		get_len(long long nb, int base)
{
	int		len;
	long	n;

	len = 0;
	n = nb;
	if (nb < 0)
		n = nb * -1;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

void			check_neg(long long *nb, char *str)
{
	if (*nb < 0)
	{
		str[0] = '-';
		*nb *= -1;
	}
}

char			*ft_lltoa_base(long long nb, int base)
{
	char	*str;
	int		len;

	len = get_len(nb, base);
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	str[len--] = '\0';
	check_neg(&nb, str);
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nb > 0)
	{
		if (nb % base >= 10)
			str[len] = ('a' - 10) + (nb % base);
		else
			str[len] = '0' + (nb % base);
		nb /= base;
		len--;
	}
	return (str);
}
