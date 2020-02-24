/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_displaynew.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 13:32:21 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 13:33:41 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

t_display		*ft_displaynew(void)
{
	t_display *new;

	if (!(new = (t_display*)malloc(sizeof(t_display))))
		return (NULL);
	new->len = 0;
	new->str = NULL;
	new->next = NULL;
	return (new);
}
