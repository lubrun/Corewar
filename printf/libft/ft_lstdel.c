/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 17:02:03 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 12:45:33 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*begin;

	begin = *alst;
	if (begin->next)
		ft_lstdel(&begin->next, del);
	del(begin->content, begin->content_size);
	free(*alst);
	*alst = NULL;
}
