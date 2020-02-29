/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 00:30:13 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/29 01:42:36 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			write_error(t_file *file, char *to_write, int ret, int line)
{
	char	*str;
	int		err_line;

	if (!line)
	{
		write(1, to_write, ft_strlen(to_write));
		free(to_write);
		return (ret);
	}
	if (file->error_label)
		err_line = file->error_label->use_line[0];
	else
		err_line = file->current_line;
	if (!(str = ft_strjoin(to_write, " [line:", 0)) ||
	!(str = ft_strjoin(str, ft_itoa(err_line), 3)) ||
	!(str = ft_strjoin(str, "]\n", 1)))
		return (0);
	write(1, str, ft_strlen(str));
	ft_strdel(&str);
	free(to_write);
	return (ret);
}

static int	check_label_use(t_file *file)
{
	t_label	*label;
	char	*err_str;

	label = file->label;
	while (label)
	{
		if (label->byte_def == -1)
		{
			err_str = ft_strjoin("Undefined label ", label->name, 0);
			file->error_label = label;
			return (write_error(file, err_str, 0, 1));
		}
		label = label->next;
	}
	return (1);
}

int			check_error(t_file *file)
{
	char *if_error;

	if_error = NULL;
	if (file->size == 0)
	{
		if_error = ft_strdup("No instruction in file !\n");
		return (write_error(file, if_error, 0, 0));
	}
	if (file->size > CHAMP_MAX_SIZE)
		return (write_error(file, ft_strdup("Champ size too long !\n"), 0, 0));
	if (!check_label_use(file))
		return (0);
	return (1);
}
