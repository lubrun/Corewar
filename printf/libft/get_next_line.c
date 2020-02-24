/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 12:17:18 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:09:29 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	*ft_read(char *str, const int fd, int *ret)
{
	char	buf[BUFF_SIZE + 1];

	if ((*ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*ft_fillline(char *str, int fd, char **line, int *ret)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	index = 0;
	while (!ft_strchr(str, '\n') && *ret)
	{
		tmp = str;
		str = ft_read(tmp, fd, ret);
		if (*ret)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\0')
		*line = ft_strdup(str);
	else if (str[index] == '\n')
		*line = ft_strsub(str, 0, index++);
	ft_strcpy(str, &str[index]);
	return (str);
}

t_list	*ft_makelist(t_list *list, t_list **tmp, int fd)
{
	char *str;

	str = "";
	if (!list)
	{
		list = ft_lstnew(str, fd);
		*tmp = list;
	}
	else
	{
		*tmp = list;
		while (list->next != NULL && (int)list->content_size != fd)
			list = list->next;
		if ((int)list->content_size != fd)
		{
			list->next = ft_lstnew(str, fd);
			list = list->next;
		}
	}
	return (list);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	tmp = NULL;
	ret = 1;
	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	list = ft_makelist(list, &tmp, fd);
	list->content = ft_fillline(list->content, list->content_size, line, &ret);
	if (!ft_strlen(list->content) && ret == 0)
	{
		if (!ft_strlen(*line))
		{
			list = ft_dellist(tmp, list);
			free(*line);
			*line = NULL;
			return (0);
		}
	}
	list = tmp;
	return (1);
}
