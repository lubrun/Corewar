/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:48:26 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/26 20:14:14 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*insert_token_error(char **split)
{
	char *new;

	if (!(new = ft_strjoin("Unknow token [", split[0], 0)) ||
		!(new = ft_strjoin(new, "]", 1)))
		return (NULL);
	ft_2dstrdel(&split);
	return (new);
}

int         is_valid_op(t_file *file, t_op *op, char *str, int label)
{
    char **split;
    
    if (!(split = ft_strsplit(str, " \t")))
        return (0);
	if (ft_str_is_whitespace(str))
	{
        ft_2dstrdel(&split);
		return (-1);
	}
	if ((*op = get_op_by_name(split[0])).id < 0)
    {
        if (!label)
            return (write_error(file, insert_token_error(split), 0, 1));
        ft_2dstrdel(&split);
        return (0);
    }
    ft_2dstrdel(&split);
    return (1);
}