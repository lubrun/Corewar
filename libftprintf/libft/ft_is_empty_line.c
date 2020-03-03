/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:42:05 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:53:46 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_empty_line(char *line)
{
	if (line)
	{
		if (*line == '\0')
			return (1);
		while (*line && (*line == ' ' ||
			*line == '\t'))
			line++;
		if (*line == '\0')
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}
