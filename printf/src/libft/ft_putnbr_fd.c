/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 17:34:43 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 14:45:34 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nomber;
	int		negative;

	nomber = n;
	negative = 1;
	if (nomber < 0)
	{
		nomber = -nomber;
		negative = -1;
		ft_putchar_fd('-', fd);
	}
	if (nomber >= 10)
	{
		ft_putnbr_fd(nomber / 10, fd);
	}
	if (nomber >= 0)
		ft_putchar_fd(nomber % 10 + '0', fd);
}
