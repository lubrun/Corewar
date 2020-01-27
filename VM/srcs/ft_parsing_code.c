/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing_code.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 16:52:12 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 10:02:49 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	check les 4 octets nulls(132->136) + les 4 octets suivant (136->140)
**	contenant la size du code
*/

int			ft_check_code_size(int *tab, t_player *play)
{
	int	index;
	int	max;
	int	exposant;

	exposant = 16777216;
	index = 8 + PROG_NAME_LENGTH;
	max = index + 4;
	while (index < max)
	{
		play->code_size += (tab[index] * exposant);
		index++;
		exposant = (exposant / 256);
	}
//	printf("SIZE == [%d]\n",play->code_size);
	if (play->code_size > CHAMP_MAX_SIZE)
		return (0);
	return (1);
}

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
//	printf("code == [%s]\n" , play->code);
	return (1);
}
