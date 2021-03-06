/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:10:13 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/29 20:50:40 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

unsigned long	handle_label(t_file *file, t_op op, char *param,
	t_arg_type type)
{
	t_label			*label;
	long int		value;

	if ((label = get_label_by_name(file->label, param, 0)))
	{
		value = file->opc_index - label->byte_def;
		return (((type == T_DIR) ? 0xFFFFFFFF : 0xFFFF) - value + 1);
	}
	else
		new_label_use(file, param, (!op.label_size && type == T_DIR) ? 4 : 2);
	return (0);
}

static int		insert_value(t_file *file, unsigned long *value, t_op op,
	t_arg_type type)
{
	(!op.label_size && type == T_DIR) ? swap_four((unsigned int *)value) :
	swap_two((unsigned short int *)value);
	ft_memcpy(&file->bytes[file->size % CHAMP_MAX_SIZE],
	value, (op.label_size == 1 ||
	type == T_IND) ? IND_SIZE : DIR_SIZE);
	if (!op.label_size && type != T_IND)
		file->size += DIR_SIZE;
	else
		file->size += IND_SIZE;
	return (1);
}

int				write_dir_ind(t_file *file, t_op op, char *param,
	t_arg_type type)
{
	unsigned long	value;

	if (type == T_DIR)
		param++;
	if (*param == LABEL_CHAR)
		value = handle_label(file, op, param + 1, type);
	else
	{
		value = (unsigned long)ft_atoull(param) %
			((!op.label_size && type == T_DIR) ?
		((long)UINT32_MAX + 1) : ((long)UINT16_MAX + 1));
	}
	if (*param != LABEL_CHAR && ((*param == '-' &&
		ft_atoll(param) < (long long)INT32_MIN) ||
		(ft_atoll(param) > UINT32_MAX)))
	{
		return (write_error(file,
		ft_strdup("Parameter value must be between INT32_MIN and UINT32_MAX\n"),
		0, 0));
	}
	return (insert_value(file, &value, op, type));
}

char			*get_output_name(char *name)
{
	char	*output_name;

	if (!(output_name = ft_strsub(name, 0, ft_strrchr(name, '.') - name + 1)))
		return (NULL);
	if (!(output_name = ft_strjoin(output_name, "cor", 1)))
		return (NULL);
	return (output_name);
}

int				write_file(t_file *file)
{
	char	*output_name;
	int		fd;
	int		prog_size;

	if (!check_error(file) || !(output_name = get_output_name(file->file_name)))
		return (0);
	if ((fd = open(output_name, O_CREAT | O_RDWR | O_TRUNC,
		S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
		return (0);
	prog_size = file->size;
	swap_four((unsigned int *)&prog_size);
	ft_memcpy(&file->header.prog_size, &(prog_size), sizeof(unsigned int));
	write(fd, &(file->header), sizeof(t_header));
	write(fd, &(file->bytes[0]), file->size);
	write(1, "File created: ", 14);
	write(1, output_name, ft_strlen(output_name));
	write(1, "\n", 1);
	ft_strdel(&output_name);
	return (1);
}
