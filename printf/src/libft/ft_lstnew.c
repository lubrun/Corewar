/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 15:01:59 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 20:37:03 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*dest;

	new = NULL;
	dest = NULL;
	if (!content)
		content_size = 0;
	if (!(new = malloc(sizeof(size_t) * (content_size))))
		return (NULL);
	if (!(dest = malloc(sizeof(size_t) * (content_size))))
		return (0);
	if (content)
		ft_strcpy(dest, content);
	else
		dest = NULL;
	new->content = (void*)dest;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
