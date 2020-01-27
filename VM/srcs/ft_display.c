/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/26 09:38:21 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 10:04:13 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

void	ft_display_play(t_player *play)
{
	while (play)
	{
		printf("\nN*[%d]\nName[%s]\nCom[%s]\nCodeSize[%d]\nCode[%s]\n",
				play->id, play->name, play->comment, play->code_size,
				play->code);
		play = play->next;
	}
}
