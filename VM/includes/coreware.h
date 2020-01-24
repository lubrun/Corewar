/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coreware.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 18:45:42 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 18:23:58 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWARE_H

# define COREWARE_H

# include "../../includes/op.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_player
{
	int					id;
	char				*name;
	char				*comment;
	struct s_player		*next;
	int					code_size;
	char				*code;
}						t_player;

typedef struct			s_info
{
	struct s_player		*play;
	char				*line;
	int					*intline;
}						t_info;

/*
**		PARSING PLAYER
*/

int						ft_parsing(t_info *info);
int						ft_parsing_code(t_info *info, t_player *player);

/*
**		UTILS
*/

t_player				*ft_new_player(t_player *player);
t_info					*ft_new_info(t_info *info);

/*
**		ERROR
*/

int						ft_error(int ret, char *str);
char					*ft_chars_error(char *ret, char *str);

#endif
