/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel_str.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 12:17:50 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:08:39 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

void	ft_lstdel_str(t_data *list)
{
	t_data	*begin;

	begin = list;
	if (begin->next)
		ft_lstdel_str(begin->next);
	free(list->str);
	free(list);
	list = NULL;
}
