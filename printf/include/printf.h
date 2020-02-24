/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 19:34:00 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 12:33:50 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_display
{
	char				*str;
	int					len;
	struct s_display	*next;
}				t_display;

typedef struct	s_data
{
	char			*str;
	int				len;
	char			attribute[5];
	int				width;
	char			asterix;
	int				precision;
	char			mode[3];
	char			convert;
	struct s_data	*next;

}				t_data;

int				ft_printf(const char *format, ...)
				 __attribute__((format(printf,1,2)));
int				ft_read_printf(const char *str, t_data *list, va_list params);
int				ft_malloc_liststr(const char *str, t_data *list, int index);
int				ft_parse(const char *str, t_data *list, va_list params);
char			ft_str_isconvert(const char *str);
int				ft_isconvert(const char *str);
t_data			*ft_datanew(void);
t_display		*ft_displaynew(void);
int				ft_is_attribute(const char c);
int				ft_choose_params(t_data *list, va_list params);
int				ft_make_strconvert_d(t_data *list, va_list params);
int				ft_make_strconvert_c(t_data *list, va_list params);
int				ft_make_strconvert_p(t_data *list, va_list params);
int				ft_make_strconvert_s(t_data *list, va_list params);
int				ft_make_strconvert_x(t_data *list, va_list params);
int				ft_make_strconvert_o(t_data *list, va_list params);
int				ft_make_strconvert_u(t_data *list, va_list params);
int				ft_make_strconvert_f(t_data *list, va_list params);
int				ft_make_strconvert_pc(t_data *list);
char			*ft_trans_floatation(t_data *list, long double decimal);
void			ft_lstdel_str(t_data *list);

#endif
