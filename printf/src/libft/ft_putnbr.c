/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 17:11:30 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 14:45:18 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nomber;
	int		negative;

	nomber = n;
	negative = 1;
	if (nomber < 0)
	{
		nomber = -nomber;
		negative = -1;
		ft_putchar('-');
	}
	if (nomber >= 10)
	{
		ft_putnbr(nomber / 10);
	}
	if (nomber >= 0)
		ft_putchar(nomber % 10 + '0');
}
