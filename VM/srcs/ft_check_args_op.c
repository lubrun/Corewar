/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_args_op.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 13:45:04 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 18:45:48 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	CHECK FOR AND 6 OR 7 XOR 8
*/

int		ft_check_arg_op_bits(int tab[4], t_chariot *pc)
{
	int index;

	printf("PASS AND OR XOR\n");
	index = -1;
	if (tab[3] != 0)
		return (ft_error(0, "TROP DE ARG POUR OP\n"));
	while (++index < 2)
		if (tab[index] <= 0 || tab[index] > 3)
			return (ft_error(0, "BAD ARG FOR OP\n"));
	if (tab[2] != 1)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	printf("OK 6 7 8\n");
	return (ft_size_to_read(tab, 4, pc));
}

/*
**	CHECK FOR ADD 4 SUB 5
*/

int		ft_check_arg_op_addsub(int tab[4], t_chariot *pc)
{
	int index;

	printf("PASS ADD SUB\n");
	index = -1;
	if (tab[3] != 0)
		return (ft_error(0, "TROP DE ARG POUR OP\n"));
	while (++index < 3)
		if (tab[index] != 1)
			return (ft_error(0, "BAD ARG FOR OP\n"));
	printf("OK 4 5\n");
	return (ft_size_to_read(tab, 0, pc));
}

/*
**	CHECK FOR ST 3
*/

int		ft_check_arg_op_st(int tab[4], t_chariot *pc)
{
	int index;

	printf("PASS ST\n");
	index = 1;
	if (tab[0] != 1 || (tab[1] != 1 && tab[1] != 3))
		return (ft_error(0, "BAD ARG FOR OP\n"));
	while (++index < 4)
		if (tab[index] != 0)
			return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 3\n");
	return (ft_size_to_read(tab, 0, pc));
}

/*
**	CHECK FOR LD 2 LLD 13
*/

int		ft_check_arg_op_ld(int tab[4], t_chariot *pc)
{
	int index;

	printf("PASS LD LLD\n");
	index = 1;
	if (tab[0] <= 1 || tab[1] != 1)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	while (++index < 4)
		if (tab[index] != 0)
			return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 2 13\n");
	return (ft_size_to_read(tab, 4, pc));
}

/*
**	CHECK FOR ZJUMP 9 FORK 12 LFORK 15
*/

int		ft_check_arg_op_jf(int tab[4], t_chariot *pc)
{
	int index;

	printf("PASS JUMP FORKS\n");
	index = 0;
	if (tab[0] != 2)
		return (ft_error(0, "BAD ARG FOR OP\n"));
	while (++index < 4)
		if (tab[index] != 0)
			return (ft_error(0, "TROP DE ARG POUR OP\n"));
	printf("OK 9 12 15\n");
	return (ft_size_to_read(tab, 4, pc));
}
