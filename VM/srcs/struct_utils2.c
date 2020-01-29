/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 16:25:57 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 14:54:59 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**		FONCTION[16] POUR CHECK LES ARG D'OPC (REF ft_check_args_op.c)
*/

void		ft_add_fonction_to_info(t_info *info)
{
	info->fonction_check[0] = ft_check_arg_op_ljf;
	info->fonction_check[1] = ft_check_arg_op_ld;
	info->fonction_check[2] = ft_check_arg_op_st;
	info->fonction_check[3] = ft_check_arg_op_addsub;
	info->fonction_check[4] = ft_check_arg_op_addsub;
	info->fonction_check[5] = ft_check_arg_op_bits;
	info->fonction_check[6] = ft_check_arg_op_bits;
	info->fonction_check[7] = ft_check_arg_op_bits;
	info->fonction_check[8] = ft_check_arg_op_ljf;
	info->fonction_check[9] = ft_check_arg_op_ldi;
	info->fonction_check[10] = ft_check_arg_op_sti;
	info->fonction_check[11] = ft_check_arg_op_ljf;
	info->fonction_check[12] = ft_check_arg_op_ld;
	info->fonction_check[13] = ft_check_arg_op_ldi;
	info->fonction_check[14] = ft_check_arg_op_ljf;
	info->fonction_check[15] = ft_check_arg_op_aff;
}

int			ft_opcode(int opc, int op, t_info *info)
{
	int		tab[4];

	if ((((opc % 64) % 16) % 4) != 0)
		return (ft_error(0, "BAD OPC LAST BINARY NOT EMPTY\n"));
	if (op < 1 || op > 16)
		return (ft_error(0, "BAD OP WHEN OPC CHECKED\n"));
	tab[0] = opc >> 6;
	tab[1] = (opc >> 4) % 4;
	tab[2] = ((opc >> 2) % 16) % 4;
	tab[3] = 0;
	if (info->fonction_check[op - 1](tab))
		return (1);
	else
		return (0);
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
