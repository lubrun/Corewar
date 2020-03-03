/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:50:32 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:20:03 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPES "dDiuUoOxXfcCsSpn%"

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct			s_float
{
	int					sign:1;
	char				*left;
	char				*right;
}						t_float;

typedef struct			s_conv
{
	char				*s_value;
	char				*str;
	char				type;
	unsigned long long	ull_value;
	int					str_len;
	int					precision;
	int					width;
	int					null_char:1;
	int					prec_point:1;
	int					is_neg:1;
	int					less_flag:1;
	int					zero_flag:1;
	int					plus_flag:1;
	int					blank_flag:1;
	int					hashtag_flag:1;
	int					big_l_modif:1;
	int					l_modif:1;
	int					h_modif:1;
	int					hh_modif:1;
	struct s_float		*float_value;
}						t_conv;

typedef struct			s_pars
{
	char				*str;
	struct s_conv		*conv;
	struct s_pars		*next;
}						t_pars;

void					add_elem(t_pars **alist, t_pars *elem);
void					parse_expr(t_pars **expr);
void					conv_expr(t_pars **expr, va_list vlist);
void					handle_prec(t_pars **expr, va_list vlist);
void					handle_width(t_pars **expr);
void					big_d_prec_handle(t_conv **conv, long long value);
void					d_prec_handle(t_conv **conv, int value);
void					s_prec_handle(t_conv **conv, char *value);
void					d_width_handle(t_conv **conv);
void					x_prec_handle(t_conv **conv, unsigned long long value);
void					flags_width_handle(t_conv **conv);
void					handle_plus_width(t_conv **conv);
void					handle_blank_width(t_conv **conv);
void					handle_less_width(t_conv **conv);
void					flags_prec_handle(t_conv **conv);
void					handle_plus_prec(t_conv **conv);
void					u_prec_handle(t_conv **conv, unsigned long long value);
void					free_elem(t_pars *pars);
int						ft_printf(const char *format, ...)
						 __attribute__((format(printf,1,2)));
int						get_zero_flag(char *str);
int						get_width(char *str);
int						get_precision(t_conv *conv, char *str);
t_conv					*create_conv();
t_pars					*parse_arg(char *format);
t_pars					*create_elem(char *str);
t_float					*new_float(long double value, int precision);

#endif
