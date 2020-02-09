/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <qbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:25:57 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/08 20:07:03 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/coreware.h"

void		ft_write_on_map(t_info *info, int value, int start, int size)
{
	int				rest;
	int				swap_size;
	unsigned int	val;

	val = value;
	rest = 1;
	swap_size = size;
	if (start < 0)
		start += MEM_SIZE;
	while (--swap_size > 0)
		rest *= 256;
	while (size)
	{
		info->map[start] = (val / rest);
		printf("MAP ==  [%d]/[%d]=[%d]map[%d][%x]\n", val, rest, val / rest, start, info->map[start]);
		val = (unsigned int)val % rest;
		rest /= 256;
		size--;
		start = (start + 1) % MEM_SIZE;
	}
}

t_chariot	*ft_new_chariot2(t_chariot *pc)
{
	int	index;

	index = -1;
	while (++index < 4)
	{
		pc->tab_jump[index] = 0;
		pc->type_arg[index] = 0;
		if (index < 3)
			pc->arg[index] = 0;
	}
	pc->op = 0;
	pc->opc = 0;
	pc->next = NULL;
	return (pc);
}

/*
**		FONCTION[16] POUR CHECK LES ARG D'OPC (REF ft_check_args_op.c)
*/

void		ft_add_fonction_to_info(t_info *info)
{
	info->fonction_check[0] = ft_check_arg_op_live;
	info->fonction_check[1] = ft_check_arg_op_ld;
	info->fonction_check[2] = ft_check_arg_op_st;
	info->fonction_check[3] = ft_check_arg_op_addsub;
	info->fonction_check[4] = ft_check_arg_op_addsub;
	info->fonction_check[5] = ft_check_arg_op_bits;
	info->fonction_check[6] = ft_check_arg_op_bits;
	info->fonction_check[7] = ft_check_arg_op_bits;
	info->fonction_check[8] = ft_check_arg_op_jf;
	info->fonction_check[9] = ft_check_arg_op_ldi;
	info->fonction_check[10] = ft_check_arg_op_sti;
	info->fonction_check[11] = ft_check_arg_op_jf;
	info->fonction_check[12] = ft_check_arg_op_ld;
	info->fonction_check[13] = ft_check_arg_op_ldi;
	info->fonction_check[14] = ft_check_arg_op_jf;
	info->fonction_check[15] = ft_check_arg_op_aff;
	ft_add_vm_fonction(info);
	ft_add_cast(info);
}

//////////////// VIRER LES FT_ERROR ET PRINTF LA ET DANS ft_check_args_op

int			ft_opcode(int opc, int op, t_info *info, t_chariot *pc)
{
	int		tab[4];
	int		index;

	index = -1;
	if ((((opc % 64) % 16) % 4) != 0)
		return (ft_error(0, "BAD OPC LAST BINARY NOT EMPTY\n"));
	if (op < 1 || op > 16)
		return (ft_error(0, "BAD OP WHEN OPC CHECKED\n"));
	tab[0] = opc >> 6;
	tab[1] = (opc >> 4) % 4;
	tab[2] = ((opc >> 2) % 16) % 4;
	tab[3] = 0;
	while (++index < 3)
	{
		pc->type_arg[index] = tab[index];
		printf("\tMAP OP [%d] type[%d] == [%d]\n", op, index, pc->type_arg[index]);
	}
	if ((pc->jump = info->fonction_check[op - 1](tab, pc)) == 0)
	{
		printf("MAP type [[[%d]]]\n", pc->type_arg[0]);
		return (0);
	}
	printf("MAP type [[[%d]]]\n", pc->type_arg[0]);
	return (1);
}

void		ft_addchariot(t_chariot **alst, t_chariot *new_chariot)
{
	t_chariot *tmp;

	if (*alst == NULL)
		*alst = new_chariot;
	else
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_chariot;
	}
}
