/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_strconvert_pc.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 20:38:38 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 15:18:12 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

int			ft_percentage(t_data *list, char c)
{
	int len;

	list->str[0] = '%';
	list->str[1] = '\0';
	len = 1;
	len = ft_strlen(list->str);
	if (list->width > len && list->attribute[2] == '-')
		ft_strnadd(&list->str[len], c, (list->width - len));
	else if (list->width > len && list->attribute[2] != '-')
		ft_strfadd(list->str, c, (list->width - len));
	list->len = ft_strlen(list->str);
	return (1);
}

int			ft_make_strconvert_pc(t_data *list)
{
	int				max_len;
	int				len;
	char			c;

	len = 1;
	max_len = 1;
	c = ' ';
	if (list->attribute[0] == '0')
		c = '0';
	max_len = list->width > 1 ? list->width : max_len;
	if ((list->str = (char*)malloc(sizeof(char*) * (max_len + 1))) == NULL)
		return (-1);
	ft_percentage(list, c);
	return (1);
}
