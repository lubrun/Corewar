/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 16:27:16 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 16:34:16 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"


char		*ft_chars_error(char *ret, char *str)
{
	ft_putstr(str);
	return (ret);
}

int			ft_error(int ret, char *str)
{
	ft_putstr(str);
	return (ret);
}
