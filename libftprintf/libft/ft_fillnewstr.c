/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillnewstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:13:35 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:53:25 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillnewstr(size_t len, char c)
{
	char *str;

	str = ft_strnew(len);
	ft_memset(str, c, len);
	return (str);
}
