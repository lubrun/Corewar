/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 23:26:50 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 16:54:01 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_header    *new_header()
{
    t_header *header;
    
    if (!(header = ft_memalloc(sizeof(t_header))))
        return (NULL);
    ft_bzero(header, sizeof(t_header));
    return (header);
}
