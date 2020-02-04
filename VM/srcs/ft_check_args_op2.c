/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_args_op2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 13:56:57 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 16:53:58 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_size_to_read(int tab[4], int direct, t_chariot *pc)
{
	int	index;
	int	octal;

	octal = 0;
	index = -1;
	while (tab[++index])
	{
		pc->type_arg[index] = pc->tab_jump[index];
		if (tab[index] == 2)
		{
			pc->tab_jump[index] = direct;
			octal += direct;
		}
		else if (tab[index] == 3)
		{
			pc->tab_jump[index] = 2;
			octal += 2;
		}
		else
		{
			pc->tab_jump[index] = tab[index];
			octal += tab[index];
		}
	}
	pc->jump = octal;
	return (octal);
}

/*
**	CHECK FOR AFF 16
*/

int		ft_check_arg_op_aff(int tab[4], t_chariot *pc)
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
	return (ft_size_to_read(tab, 0, pc));
}

/*
**	CHECK FOR STI 11
*/

int		ft_check_arg_op_sti(int tab[4], t_chariot *pc)
{
	printf("PASS LD STI\n");
	if (tab[1] < 1 || tab[1] > 3)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[2] < 1 || tab[2] > 2 || tab[0] != 1)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[3] != 0)
		return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 11\n");
	return (ft_size_to_read(tab, 2, pc));
}

/*
**	CHECK FOR LDI 10 LLDI 14
*/

int		ft_check_arg_op_ldi(int tab[4], t_chariot *pc)
{
	printf("PASS LD LDI\n");
	if (tab[0] < 1 || tab[0] > 3)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[1] < 1 || tab[1] > 2 || tab[2] != 1)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[3] != 0)
		return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 10 14\n");
	return (ft_size_to_read(tab, 2, pc));
}

/*
**		LIVE 1
*/

int		ft_check_arg_op_live(int tab[4], t_chariot *pc)
{
	int index;

	printf("PASS LIVE\n");
	index = 0;
	if (tab[0] != 2)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	while (++index < 4)
		if (tab[index] != 0)
			return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 1\n");
	return (ft_size_to_read(tab, 2, pc));
}
