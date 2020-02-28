/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:40:32 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/28 19:36:15 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_op(t_file *file, char *str, int start)
{
	int		index;
	int		label;
	int		op;

	index = start;
	if (*(str + index) == COMMENT_CHAR)
		return (1);
	if ((label = is_label(file, str, &index)) < 0)
		return (0);
	if (label && ft_is_empty_line(str + index))
		return (1);
	if (!(op = is_op(file, str + index, label)))
		return (0);
	return (1);
}

int			parse_op(t_file *file)
{
	char	*str;
	int		index;

	while (get_next_line(file->fd, &str) > 0)
	{
		if (!str)
			return (0);
		file->current_line++;
		if (!(ft_is_empty_line(str)))
		{
			index = 0;
			while (str[index] && (str[index] == ' ' ||
						str[index] == '\t'))
				index++;
			if (!get_op(file, str, index))
			{
				ft_strdel(&str);
				return (0);
			}
		}
		ft_strdel(&str);
	}
	return (1);
}

void		set_magic(t_file *file)
{
	int		magic;

	magic = COREWAR_EXEC_MAGIC;
	swap_four((unsigned int *)&(magic)); 
	file->header.magic = magic;
}

int			parse_header(t_file *file)
{
	char *str;
	char *trim;

	file->error = 1;
	ft_bzero(&file->header, sizeof(t_header));
	file->header.magic = 0;
	str = NULL;
	trim = NULL;
	while (!file->header.magic && get_next_line(file->fd, &str))
	{
		if (!str || !(trim = ft_strtrim(str)))
			return (0);
		file->current_line++;
		if (!ft_is_empty_line(trim) && *trim != COMMENT_CHAR)
		{
			if ((!ft_strncmp(trim, NAME_CMD_STRING, 5) && !get_prog_name(file, &trim)) ||
					(trim && !ft_strncmp(trim, COMMENT_CMD_STRING, 8) && !get_comment(file, &trim)))
			{
				ft_strdel(&trim);
				return (0);
			}
			if (!file->header.magic && trim)
			{
				ft_strdel(&trim);
				return (write_error(file, ft_strdup("Incorrect header\n"), 0, 0));
			}
		}
		ft_strdel(&trim);
		ft_strdel(&str);
	}
	return (1);
}
