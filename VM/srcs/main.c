/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 18:45:05 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 12:33:09 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

int			ft_number_player(t_info *info)
{
	t_player	*play;
	int			index;
	int			count;

	count = 0;
	index = 0;
	play = info->play;
	while (play)
	{
		if (play->id == 0)
		{
			while (info->preset_player[index] != 0 && index < MAX_PLAYERS)
				index++;
			play->id = index + 1;
			info->preset_player[index] = index + 1;
		}
		count++;
		play = play->next;
	}
	info->nb_players = count;
	return (1);
}

char		*ft_make_file_str(int *line, int len)
{
	int		index;
	int		len_str;
	char	*str;

	index = -1;
	len_str = len * 2;
	if (!(str = malloc(sizeof(char*) * (len_str + 1))))
		return (ft_chars_error(NULL, "ERROR MALLOC STRLINE\n"));
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
	if ((ft_strlen(str) / 2) < (8 + PROG_NAME_LENGTH + COMMENT_LENGTH + 13))
		return (ft_chars_error(NULL, "CODE TROP COURT\n"));
	return (str);
}

int			ft_open(char *file, t_info *info, int num)
{
	int		fd;
	int		*line;
	int		len;
	int		index;
	int		res;

	index = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_error(0, "OPEN RETURN 0\n"));
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(line = malloc(sizeof(int*) * (len + 1))))
		return (ft_error(0, "ERROR MALLOC INTLINE\n"));
	while ((res = read(fd, &line[index], 1)) > 0)
		index++;
	if (res == -1)
		return (ft_error(0, "BAD FILE\n"));
	index = -1;
	info->line = ft_make_file_str(line, len);
	info->intline = line;
	if (!info->line || !info->intline)
		return (ft_error(0, "NO LINE \n"));
	ft_parsing(info, num);
	return (1);
}

int			main(int ac, char **av)
{
	t_info *info;

	if (ac < 2)
		return (ft_error(0, "NEED ARGUMENTS\n"));
	info = NULL;
	info = ft_new_info(info);
	printf("ARG START\n");
	if (!ft_arguments(ac, av, info))
		return (0);
	ft_number_player(info);
	ft_tri_player(info);
	ft_display_play(info->play);
	ft_build_map(info);
	return (1);
}
