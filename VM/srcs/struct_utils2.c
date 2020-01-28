/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 16:25:57 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:29:27 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_addchariot(t_chariot **alst, t_chariot *new_chariot)
{
	t_chariot *tmp;

	if (*alst == NULL)
		*alst = new_chariot;
	else
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_chariot;
	}
}
