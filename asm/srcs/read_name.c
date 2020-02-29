/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:04:28 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/29 01:09:44 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_name_tag(char *str)
{
	char	*tmp;
	char	*if_error;

	tmp = str;
	str += 5;
	if_error = NULL;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (!*str || *str != '"')
	{
		if_error = ft_strdup("Token expected:.name \"[NAME]\"\n");
		return (write_error(NULL, if_error, 0, 0));
	}
	return (str - tmp);
}

static int	check_prog_name(char *str, char **name)
{
	int		index;
	int		tmp;
	char	*if_error;

	if_error = NULL;
	if ((index = check_name_tag(str) + 1) == 1)
		return (0);
	tmp = index;
	while (str[index] && str[index] != '"')
		index++;
	if (str[index] != '"' || str[index + 1] != '\0')
	{
		if_error = ft_strdup("Token expected:.name \"[NAME]\"\n");
		return (write_error(NULL, if_error, 0, 0));
	}
	if (index - tmp > PROG_NAME_LENGTH)
		return (write_error(NULL, ft_strdup("Prog_name too long!\n"), 0, 0));
	if (!(*name = ft_strsub(str, tmp, index - tmp)))
		return (0);
	return (1);
}

int			get_prog_name(t_file *file, char **str)
{
	char	*name;

	if (file->header.prog_name[0])
		return (write_error(NULL, ft_strdup("Duplicated token .name\n"), 0, 0));
	if (!check_prog_name(*str, &name))
		return (0);
	ft_memcpy(file->header.prog_name, name, ft_strlen(name));
	ft_strdel(str);
	ft_strdel(&name);
	if (file->header.comment[0])
		set_magic(file);
	return (1);
}
