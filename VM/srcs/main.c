/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 18:45:05 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 18:25:19 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

char		*ft_make_file_str(int *line, int len)
{
	int		index;
	int		len_str;
	char	*str;

	index = 0;
	len_str = len * 2;
	if (!(str = malloc(sizeof(char*) * (len_str + 1))))
		return (ft_chars_error(NULL, "ERROR MALLOC STRLINE\n"));
	if (line[index] <= 15)
	{
		ft_strcpy(str, "0");
		ft_strcat(str, ft_lltoa_base(line[index], 16));
	}
	else
		str = ft_strcpy(str, ft_lltoa_base(line[index], 16));
	while (++index < len)
	{
		if (line[index] <= 15)
		{
			ft_strcat(str, "0");
			ft_strcat(str, ft_lltoa_base(line[index], 16));
		}
		else
			ft_strcat(str, ft_lltoa_base(line[index], 16));
	}
	printf("\n\n%s\n LEN ==%zu\n", str, ft_strlen(str));
	if ((ft_strlen(str) / 2) < (8 + PROG_NAME_LENGTH + COMMENT_LENGTH + 13))
		return (ft_chars_error(NULL, "CODE TROP COURT\n"));
	return (str);
}

int			ft_open(char *file, t_info *info)
{
	int		fd;
	int		*line;
	int		len;
	int		index;

	index = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	printf("INT len == [%d]\n", len);
	if (!(line = malloc(sizeof(int*) * (len + 1))))
		return (ft_error(0, "ERROR MALLOC INTLINE\n"));
	while (read(fd, &line[index], 1))
		index++;
	index = -1;
	while (++index < len)
		printf("%s",ft_lltoa_base(line[index], 16));
	info->line = ft_make_file_str(line, len);
	info->intline = line;
	return (1);
}

int			main(int ac, char **av)
{
	t_info *info;

	info = NULL;
	info = ft_new_info(info);
	if (ac >= 2)
		ft_open(av[1], info);
	if (!info->line || !info->intline)
		return (ft_error(0, "NO LINE \n"));
	ft_parsing(info);
	return (1);
}
