/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_isdigit.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 11:09:56 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 17:23:23 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isdigit(char *str, int len_max)
{
	int i;

	i = 0;
	if (len_max == -1)
		len_max = ft_strlen(str) + 1;
	while (i < len_max && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (!i ? 0 : 1);
}
