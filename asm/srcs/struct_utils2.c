/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:32:53 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/29 01:38:52 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_label(t_label *label)
{
	t_label *to_free;

	while (label)
	{
		ft_strdel(&label->name);
		to_free = label;
		label = label->next;
		free(to_free);
	}
}

void		free_file(t_file *file)
{
	free_label(file->label);
	ft_strdel(&file->file_name);
	free(file);
}
