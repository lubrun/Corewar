/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreware.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:16:59 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/17 11:17:00 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWARE_H

# define COREWARE_H

# include "op.h"
# include <fcntl.h>
# include <stdio.h>

/*
**	LE CHARIOT POINTE SUR LA MAP A SA "POS"
**	OP == operateur OPC == Code Operateur pour les args R == registre
*/

typedef struct			s_chariot
{
	int					*r;
	int					cycle_live;
	int					cast;
	int					carry;
	int					player;
	char				op;
	char				opc;
	int					jump;
	int					type_arg[4];
	int					tab_jump[4];
	int					arg[3];
	int					pos;
	struct s_chariot	*next;
	struct s_chariot	*start;
}						t_chariot;

typedef struct			s_op
{
	char				*name;
	int					number_args;
	int					type_arg[3];
	int					id;
	int					cast;
	char				*def;
	int					opc;
	int					long_dir;
}						t_op;

typedef struct			s_player
{
	int					id;
	char				*name;
	char				*comment;
	int					code_size;
	int					cycle_live;
	int					mapped;
	unsigned char		*code;
	struct s_player		*next;
}						t_player;

typedef struct			s_info
{
	void				(*fonction_op[16])(struct s_info *info, t_chariot *pc);
	int					(*fonction_check[16])(int tab[4], t_chariot *pc);
	struct s_chariot	*chariot;
	struct s_player		*play;
	unsigned char		*map;
	int					*preset_player;
	int					tab_cast[16];
	char				*line;
	int					aff;
	int					*intline;
	int					nb_players;
	unsigned int		verbose;
	int					cycle_total;
	int					cycle_to_die;
	int					max_check;
	int					live_total;
	int					delta;
	int					dump_size;
	int					dump_cycle;
}						t_info;

t_op					ft_op_tab[17];

/*
**		PARSING ARGUMENTS
*/

int						ft_arguments(int ac, char **av, t_info *info);
int						ft_open(char *file, t_info *info, int num);

/*
**		PARSING PLAYER
*/

int						ft_check_code_size(int *tab, t_player *play);
int						ft_parsing(t_info *info, int num);
int						ft_parsing_code(t_info *info, t_player *player);

/*
**		SET UP
*/

int						ft_build_chariot(t_info *info, int index,
		t_player *play);
int						ft_build_map(t_info *info);

/*
**	FT_CHECKS_ARGS_OPC
*/

int						ft_size_to_read(int tab[4], int direct, t_chariot *pc);
int						ft_new_jump(int tab[4], t_chariot *pc);
int						ft_check_arg_op_aff(int tab[4], t_chariot *pc);
int						ft_check_arg_op_sti(int tab[4], t_chariot *pc);
int						ft_check_arg_op_ldi(int tab[4], t_chariot *pc);
int						ft_check_arg_op_bits(int tab[4], t_chariot *pc);
int						ft_check_arg_op_addsub(int tab[4], t_chariot *pc);
int						ft_check_arg_op_st(int tab[4], t_chariot *pc);
int						ft_check_arg_op_ld(int tab[4], t_chariot *pc);
int						ft_check_arg_op_jf(int tab[4], t_chariot *pc);
int						ft_check_arg_op_live(int tab[4], t_chariot *pc);

/*
**	ALGO
*/

void					ft_winner(t_info *info, t_player *play);
int						ft_read_arguments_opc(t_info *info, t_chariot *pc);
int						ft_parcour_map(t_info *info, t_chariot *pc);
int						ft_opcode(int opc, int op, t_info *info,
		t_chariot *pc);

/*
**	FONCTIONS VM
*/

void					ft_aff(t_info *info, t_chariot *pc);
void					ft_lfork(t_info *info, t_chariot *pc);
void					ft_lldi(t_info *info, t_chariot *pc);
void					ft_lld(t_info *info, t_chariot *pc);
void					ft_fork(t_info *info, t_chariot *pc);
void					ft_sti(t_info *info, t_chariot *pc);
void					ft_ldi(t_info *info, t_chariot *pc);
void					ft_zjmp(t_info *info, t_chariot *pc);
void					ft_xor(t_info *info, t_chariot *pc);
void					ft_or(t_info *info, t_chariot *pc);
void					ft_and(t_info *info, t_chariot *pc);
void					ft_sub(t_info *info, t_chariot *pc);
void					ft_add(t_info *info, t_chariot *pc);
void					ft_st(t_info *info, t_chariot *pc);
void					ft_ld(t_info *info, t_chariot *pc);
void					ft_live(t_info *info, t_chariot *pc);

/*
**		UTILS
*/

void					ft_tri_player(t_info *info);
void					ft_del_chariot(t_info *info, t_chariot *pc);
t_chariot				*ft_pc_cpy(t_chariot *dest, t_chariot *source);
int						ft_read_at(t_info *info, int index);
int						ft_indirect_arg(t_info *info, t_chariot *pc, int arg);
void					ft_write_on_map(t_info *info, int value, int start,
		int size);
t_player				*ft_player_by_id(t_player *play, int id);
unsigned char			ft_xtoc(char str[2]);
int						ft_xtoi(char str[2]);
char					*ft_itox(int num, char str[2]);
char					*ft_ctox(unsigned char c, char str[2]);
void					ft_add_first_chariot(t_chariot **alst, t_chariot *new_chariot);
void					ft_addchariot(t_chariot **alst, t_chariot *new_chariot);
void					ft_addplayer(t_player **alst, t_player *new_player);
t_chariot				*ft_new_chariot(int player, int pos, t_info *info);
t_chariot				*ft_new_chariot2(t_chariot *pc);
t_player				*ft_new_player(t_player *player);
t_info					*ft_new_info(t_info *info);
void					ft_add_vm_fonction(t_info *info);
void					ft_add_fonction_to_info(t_info *info);
void					ft_add_cast(t_info *info);

/*
**		ERROR
*/

int						ft_error(int ret, char *str);
char					*ft_chars_error(char *ret, char str[2]);

/*
**			DISPLAY
*/

void					ft_display_chariot(t_info *info);
void					ft_display_map(t_info *info);
void					ft_display_play(t_player *play);

/*
**		VERBOSE
*/

unsigned int			get_number_verbose(char *line);
unsigned int			ft_unsigned_atoi(char *line);
short					check_bit(unsigned int var, short pos);



#endif
