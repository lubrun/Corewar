/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 23:26:50 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 09:54:26 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_label		*get_label_by_name(t_label *first, char *name, int use)
{
	if (name[ft_strlen(name) - 1] == SEPARATOR_CHAR)
		name[ft_strlen(name) - 1] = '\0';
	while (first)
	{
		if (!ft_strcmp(first->name, name))
			if ((use && first->byte_def == -1) ||
			(!use && first->byte_def != -1))
				return (first);
		first = first->next;
	}
	return (NULL);
}

int			new_label_use(t_file *file, char *name, int size)
{
	t_label	*label;

	if (!(label = get_label_by_name(file->label, name, 1)))
	{
		if (!(new_label(file, name)))
			return (0);
		file->label->byte_def = -1;
		label = file->label;
	}
	label->byte_use[label->use_count] = file->size;
	label->use_size[label->use_count++] = size;
	return (1);
}

void		fill_label(t_file *file, t_label *label)
{
	unsigned long	value;
	int				index;

	index = 0;
	while (index < label->use_count)
	{
		value = (unsigned long)(label->byte_def - label->byte_use[index]) %
		((label->use_size[index] == 2) ? (long)UINT16_MAX + 1 : (long)UINT32_MAX + 1);
		if (label->use_size[index] == 4)
			value += 2;
		(label->use_size[index] == 2) ? swap_two((unsigned short int *)&value) :
		swap_four((unsigned int *)&value);
		ft_memcpy(&file->bytes[label->byte_use[index]], &value, label->use_size[index]);
		index++;
	}
}

int         new_label(t_file *file, char *label)
{
    t_label		*new;
    t_label		*tmp;

	if ((new = get_label_by_name(file->label, label, 1)))
	{
    	new->byte_def = file->size;
		fill_label(file, new);
		return (1);
	}
    if (!label || !(new = ft_memalloc(sizeof(t_label))))
        return (0);
    ft_bzero(new, sizeof(new));
    new->byte_def = file->size;
	new->name = label;
    if (file->label)
    {
        tmp = file->label;
        file->label = new;
        new->next = tmp;
    }
    else
        file->label = new;
    return (1);
}