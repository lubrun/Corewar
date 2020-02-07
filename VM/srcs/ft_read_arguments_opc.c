/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_arguments_opc.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 18:41:56 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 18:30:33 by qbarrier    ###    #+. /#+    ###.fr     */
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
**	SI ON LIT 2 octets il faut imaginer qu'ils sont signe et qu'il peuvent etre negatif
**	D'ou la variable max qui permet de savoir si on depasse sa moitie, on devient negatif
*/

int			ft_convert(t_info *info, int *index, int size)
{
	int				res;
	int				index_modulo;
	unsigned int	max;

	max = ft_pow(256, ((size * 2) - 2));
	if (size == 4 || size == 1)
		max = 4294967295;
//	printf("MAX == [%u]\n", max);

//	printf("");	// si j'enleve le printf, je n'ai plus les meme valeure ...
	res = 0;
	while (size > 0)
	{
		index_modulo = (*index) % MEM_SIZE;
//		printf("\tJUMP arg info->map[%d|%d][%d]\n", *index, index_modulo, info->map[index_modulo]);
		res = res + ((ft_pow(16, ((size * 2) - 2))) * (info->map[index_modulo]));
		size--;
		(*index)++;
	}
	(*index) = (*index) % MEM_SIZE;
//	printf("\tMAX RES === [%d][%u]\n", res, res);
	if ((int)res > (int)(max / 2))
		res = res - max;
//	printf("\tMAX RES === [%d][%d]\n", res, res);
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
//		printf("JUMP arg 0 == [%d] info->map[pc->pos] =[%d], pc->jump {%d]\n", pc->arg[0], info->map[pc->pos], pc->jump);
//		if (pc->op == 9)
//		{
//			pc->arg[0] = ft_convert_for_jump(info, index);
//		}
//		else
			pc->arg[0] = ft_convert(info, &index, pc->jump);
		printf("JUMP arg 0 == [%d]\n", pc->arg[0]);
	}
	else 
	{
		if (pc->tab_jump[0] != 0)
			pc->arg[0] = ft_convert(info, &index, pc->tab_jump[0]);
		if (pc->opc >> 6 == 3)
			pc->arg[0] = ft_indirect_arg(info, pc, pc->arg[0]);
		if (pc->tab_jump[1] != 0)
			pc->arg[1] = ft_convert(info, &index, pc->tab_jump[1]);
		if ((pc->opc >> 4) % 4 == 3)
			pc->arg[1] = ft_indirect_arg(info, pc, pc->arg[1]);
		if (pc->tab_jump[2] != 0)
			pc->arg[2] = ft_convert(info, &index, pc->tab_jump[2]);
	}
	if (ft_check_register(pc))
		info->fonction_op[pc->op - 1](info, pc);
	return (1);
}
