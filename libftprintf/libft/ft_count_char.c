/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:17:15 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:55:11 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char(char *str, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index++] == c)
			count++;
	}
	return (count);
}
