/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coreware.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 18:45:42 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:28:33 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWARE_H

# define COREWARE_H

# include "../../includes/op.h"
# include <fcntl.h>
# include <stdio.h>

/*
**	LE CHARIOT POINTE SUR LA MAP A SA "POS"
**	OP == operateur OPC == Code Operateur pour les args R == registre
*/

typedef struct			s_chariot
{
	int					*r;
	int					carry;
	int					player;
	char				op;
	char				opc;
	int					jump;
	int					pos;
	struct s_chariot	*next;
	struct s_chariot	*start;
}						t_chariot;

typedef struct			s_player
{
	int					id;
	char				*name;
	char				*comment;
	int					code_size;
	int					mapped;
	unsigned char		*code;
	struct s_player		*next;
}						t_player;

typedef struct			s_info
{
	struct s_chariot	*chariot;
	struct s_player		*play;
	unsigned char		*map;
	int					*preset_player;
	char				*line;
	int					*intline;
	int					nb_players;
	int					verbose;
	int					dump_size;
	int					dump_cycle;
}						t_info;


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
**		UTILS
*/

t_player				*ft_player_by_id(t_player *play, int id);
unsigned char			ft_xtoc(char str[2]);
int						ft_xtoi(char str[2]);
char					*ft_itox(int num, char str[2]);
char					*ft_ctox(unsigned char c, char str[2]);
void					ft_addchariot(t_chariot **alst, t_chariot *new_chariot);
void					ft_addplayer(t_player **alst, t_player *new_player);
t_chariot				*ft_new_chariot(int player, int pos, t_info *info);
t_player				*ft_new_player(t_player *player);
t_info					*ft_new_info(t_info *info);

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


#endif
