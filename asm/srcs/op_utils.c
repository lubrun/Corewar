/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/25 23:13:01 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 17:48:48 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void    write_param(t_file *file, t_op op, char *param, t_arg_type type)
{
    unsigned char   add_opp; 

    if (type == T_REG)
    {
        add_opp = 64;
        file->bytes[file->size % CHAMP_MAX_SIZE] = ft_atoi(param + 1);
		file->size += REG_SIZE;
    }
    else if (type == T_DIR || type == T_IND)
    {
        add_opp = (type == T_DIR) ? 128 : 192;
        write_dir_ind(file, op, param, type);
    }
    if (file->param_index == 0)
        file->opp += add_opp;
    else if (file->param_index == 1)
        file->opp += (add_opp >> 2);
    else if (file->param_index == 2)
        file->opp += (add_opp >> 4);
	// printf("OPP{%.2x}\n", file->opp);
    file->param_index++;
}

int     is_valid_reg(char *param)
{
    int reg;

    if (*param != 'r' && !ft_str_isdigit(param, ft_strlen(param + 1)))
        return (0);
    reg = ft_atoi(param + 1);
    if (reg > 0 && reg <= REG_NUMBER)
        return (1);
    return (0);
}

int     is_valid_dir(char *param)
{
    if (*param != DIRECT_CHAR)
        return (0);
    if (*(param + 1) != LABEL_CHAR &&
        !ft_str_isdigit(param + 1, ft_strlen(param + 1)))
        return (0);
    return (1);
}

int     is_valid_ind(char *param)
{;
	if (*param != LABEL_CHAR && !ft_str_isdigit(param, ft_strlen(param + 1)))
        return (0);
    return (1);
}

t_arg_type  get_param_type(char *param, t_op op, int index)
{
    t_arg_type type;
;
    type = -1;
    if ((op.params_type[index] & T_REG) >= 1 && is_valid_reg(param))
        type = T_REG;
    else if ((op.params_type[index] & T_DIR) >= 1 && is_valid_dir(param))
        type = T_DIR;
    else if ((op.params_type[index] & T_IND) >= 1 && is_valid_ind(param))
        type = T_IND;
    return (type);
}