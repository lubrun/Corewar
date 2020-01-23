/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_inttablen.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 20:59:34 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 21:06:47 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_inttablen(int *tab, int limit)
{
    size_t len;

    if (!tab)
        return (0);
    len = 0;
    while (tab[len] && tab[len] != limit)
        len++;
    return (len);
}