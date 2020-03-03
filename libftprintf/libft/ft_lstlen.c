/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 18:51:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 17:30:41 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_lstlen(t_list **alst)
{
	t_list	*lst;
	size_t	len;

	if (!alst)
		return (0);
	lst = *alst;
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
