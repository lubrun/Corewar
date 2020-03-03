/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_whitespace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:57:30 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/26 19:59:30 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_whitespace(char *str)
{
	while (ft_is_whitespace(*str))
		str++;
	if (!*str)
		return (1);
	return (0);
}