/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_datanew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 12:23:54 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 13:44:48 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** Initialisation des donnees
*/

t_data		*ft_datanew(void)
{
	t_data *new;

	if (!(new = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	new->str = NULL;
	new->len = 0;
	bzero(new->attribute, 5);
	new->width = 0;
	new->asterix = '\0';
	new->precision = -1;
	bzero(new->mode, 4);
	new->convert = 0;
	new->next = NULL;
	return (new);
}
