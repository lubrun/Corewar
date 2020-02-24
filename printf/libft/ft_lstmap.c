/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 13:12:05 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 19:45:21 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;

	if (!lst)
		return (0);
	res = NULL;
	if (!(res = malloc(sizeof(size_t) * lst->content_size)))
		return (0);
	res = f(lst);
	if (lst->next)
		res->next = ft_lstmap(lst->next, f);
	return (res);
}
