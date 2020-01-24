/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing_code.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 16:52:12 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 18:25:17 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	(PROG_LENGTH 128 + COMM_LENGTH 2048 + 8 NULL + 4 CODE SIZE + 4 MAGIC )
**	=>2192
*/

int			ft_parsing_code(t_info *info, t_player *play)
{
	int	index;
	int	swap;
	int	len;

	index = (PROG_NAME_LENGTH + COMMENT_LENGTH + 16) * 2;//2192
	swap = index;
	len = (int)ft_strlen(&info->line[index]);
	if (len != (play->code_size * 2))
		return (ft_error(0, "CODE DU CHAMP INVALIDE\n"));
	if (!(play->code = malloc(sizeof(char*) * (len + 1))))
		return (ft_error(0, "ERROR MALLOC player->code\n"));
	ft_strcpy(play->code, &info->line[index]);
	printf("code == [%s]\n" , play->code);


	return (1);
}
