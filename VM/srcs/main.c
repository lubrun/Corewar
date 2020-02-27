/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:11 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/27 16:58:15 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
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

char		*ft_make_file_str(t_info *info, int *line, int len)
{
	int		index;
	int		len_str;
	char	*lltoa;

	index = -1;
	len_str = len * 2;
	if (!(info->line = ft_memalloc(sizeof(char) * (len_str + 1))))
		return (ft_chars_error(NULL, "ERROR MALLOC STRLINE\n"));
	while (++index < len)
	{
		lltoa = ft_lltoa_base(line[index], 16);
		if (line[index] <= 15)
		{
			ft_strcat(info->line, "0");
			ft_strcat(info->line, lltoa);
		}
		else
			ft_strcat(info->line, lltoa);
		free(lltoa);
	}
	if ((ft_strlen(info->line) / 2) < (8 + PROG_NAME_LENGTH +
				COMMENT_LENGTH + 13))
		return (ft_chars_error(NULL, "CODE TROP COURT\n"));
	return (info->line);
}

int			ft_open(char *file, t_info *info, int num)
{
	int		fd;
	int		len;
	int		index;
	int		res;

	index = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_error(0, "OPEN RETURN 0\n"));
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(info->intline = ft_memalloc(sizeof(int) * (len + 1))))
		return (ft_close_error(0, "ERROR MALLOC INTLINE\n", fd));
	while ((res = read(fd, &info->intline[index], 1)) > 0)
		index++;
	if (res == -1)
		return (ft_close_error(0, "BAD FILE\n", fd));
	ft_make_file_str(info, info->intline, len);
	if (!info->line || !info->intline)
		return (ft_close_error(0, "NO LINE \n", fd));
	close(fd);
	ft_parsing(info, num);
	return (1);
}

int			main(int ac, char **av)
{
	t_info *info;

	info = NULL;
	if (ac < 2)
	{
		ft_free_all(info);
		return (ft_error(0, "NEED ARGUMENTS\n"));
	}
	info = NULL;
	info = ft_new_info(info);
	if (!ft_arguments(ac, av, info))
	{
		ft_free_all(info);
		return (0);
	}
	ft_number_player(info);
	ft_tri_player(info);
	ft_display_play(info->play);
	ft_build_map(info);
	ft_free_all(info);
	return (1);
}
