/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_arguments_opc.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 18:41:56 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 18:01:09 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**		VERIFIE SI LE REGISTRE EXISTE SI OUI LE STOCK DANS ARG
*/

int			ft_check_register(t_chariot *pc)
{
	int index;

	index = 0;
	while (index < 3)
	{
		if (pc->type_arg[index] == 1 && (pc->arg[index] < 1 ||
					pc->arg[index] > 16))
			return (0);
		index++;
	}
	return (1);
}

/*
**	CONVERTI SUR SIZE OCTET LA VALEUR EX EN DEC ET LA STOCK DANS ARG
*/

int			ft_convert(t_info *info, int *index, int size)
{
	int	res;
	int	max;
	int	index_modulo;

	res = 0;
	max = (*index) + size;
	while ((*index) < max)
	{
		index_modulo = (*index) % MEM_SIZE;
		res += (ft_pow(16, ((size * 2) - 2))) * info->map[index_modulo];
		size--;
		(*index) = (*index + 1);
	}
	return (res);
}

/*
**	Recuperer les Arguments avec l'opc, checker les registres, envoyer dans la fonction
*	|| revenir et faire un saut de chariot->jump octet sur le pointeur du chariot.
*/

int			ft_read_arguments_opc(t_info *info, t_chariot *pc)
{
	int index;

	index = pc->pos;
	if (!pc->opc)
	{
		printf("JUMP arg 0 == [%d]\n", pc->arg[0]);
		pc->arg[0] = ft_convert(info, &index, pc->jump);
		printf("JUMP arg 0 == [%d]\n", pc->arg[0]);
	}
	else 
	{
		if (pc->type_arg[0] != 0)
			pc->arg[0] = ft_convert(info, &index, pc->type_arg[0]);
		if (pc->opc >> 6 == 3)
			pc->arg[0] = ft_indirect_arg(info, pc, pc->arg[0]);
		if (pc->type_arg[1] != 0)
			pc->arg[1] = ft_convert(info, &index, pc->type_arg[1]);
		if ((pc->opc >> 4) % 4 == 3)
			pc->arg[1] = ft_indirect_arg(info, pc, pc->arg[1]);
		if (pc->type_arg[2] != 0)
			pc->arg[2] = ft_convert(info, &index, pc->type_arg[2]);
	}
	if (ft_check_register(pc))
		info->fonction_op[pc->op - 1](info, pc);
	printf("\t------ARGS [%d][%d][%d]\n", pc->arg[0], pc->arg[1], pc->arg[2]);
	return (1);
}
