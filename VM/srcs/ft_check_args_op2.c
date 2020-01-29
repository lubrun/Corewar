/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_args_op2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 13:56:57 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 14:46:39 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	CHECK FOR AFF 16
*/

int		ft_check_arg_op_aff(int tab[4])
{
	int index;

	printf("PASS LD AFF\n");
	index = 0;
	if (tab[0] != 1)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	while (++index < 4)
		if (tab[index] != 0)
			return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 16\n");
	return (1);
}

/*
**	CHECK FOR STI 11
*/

int		ft_check_arg_op_sti(int tab[4])
{
	printf("PASS LD STI\n");
	if (tab[1] < 1 || tab[1] > 3)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[2] < 1 || tab[2] > 2 || tab[0] != 1)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[3] != 0)
		return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 11\n");
	return (1);
}

/*
**	CHECK FOR LDI 10 LLDI 14
*/

int		ft_check_arg_op_ldi(int tab[4])
{
	printf("PASS LD LDI\n");
	if (tab[0] < 1 || tab[0] > 3)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[1] < 1 || tab[1] > 2 || tab[2] != 1)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[3] != 0)
		return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 10 14\n");
	return (1);
}
