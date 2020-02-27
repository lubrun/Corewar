/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:00:33 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/27 17:25:36 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

unsigned char		ft_xtoc(char str[2])
{
	unsigned char	num;
	int				index;
	int				hex;

	hex = 16;
	index = 0;
	num = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			num += ((str[index] - 48) * hex);
		else if (str[index] >= 'a' && str[index] <= 'f')
			num += ((str[index] - 87) * hex);
		else
		{
			printf("\t\t ERROR XTOC\n");
			return (0);
		}
		index++;
		hex = 1;
	}
	return (num);
}

int					ft_xtoi(char str[2])
{
	int	num;
	int	index;
	int	hex;

	hex = 16;
	index = 0;
	num = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			num += ((str[index] - 48) * hex);
		else if (str[index] >= 'a' && str[index] <= 'f')
			num += ((str[index] - 87) * hex);
		else
		{
			printf("\t\t ERROR XTOC\n");
			return (0);
		}
		index++;
		hex = 1;
	}
	return (num);
}

char				*ft_itox(int num, char str[2])
{
	int	tmp;

	if (num < 0 || num > 255)
		return (NULL);
	ft_strcpy(str, "00");
	if (num >= 16)
	{
		tmp = num / 16;
		num = num % 16;
		if (tmp >= 10)
			str[0] = tmp + 87;
		else
			str[0] = tmp + 48;
	}
	tmp = num;
	if (tmp >= 10)
		str[1] = tmp + 87;
	else
		str[1] = tmp + 48;
	return (str);
}

char				*ft_ctox(unsigned char c, char str[2])
{
	int	tmp;

	ft_strcpy(str, "00");
	if (c >= 16)
	{
		tmp = c / 16;
		c = c % 16;
		if (tmp >= 10)
			str[0] = tmp + 87;
		else
			str[0] = tmp + 48;
	}
	tmp = c;
	if (tmp >= 10)
		str[1] = tmp + 87;
	else
		str[1] = tmp + 48;
	return (str);
}
