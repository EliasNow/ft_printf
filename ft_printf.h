/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 22:27:10 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/13 21:20:04 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int				asterisk;
	int				dot;
	int				hash;
	int				left_justify;
	int				plus;
	int				inv_plus;
	int				percent;
	int				precision;
	int				zero;
	struct s_flags	*next;
}					t_flags;

typedef struct		s_string
{
	int				skip_percent;
	char			*str;
	size_t			n;
	int				edge;
	int				error;
	int				free;
	int				neg;
	int				field_padding;
	int				field_printed;
	int				nb_padding;
	int				nb_printed;
	int				width;
	size_t			len;
	t_flags			*flags;
}					t_string;

void				c_print(t_string *ts, va_list *arg_ptr);
int					ft_printf(const char *input_str, ...);
void				calc_hex_padding(t_string *ts);
void				calc_int_padding(t_string *ts);
void				calc_u_int_padding(t_string *ts);
void				calc_str_padding(t_string *ts);
void				caps_simple_print(t_string *ts, char *input_str);
const char			*find_width(t_string *ts, const char *input_str, \
va_list *arg_ptr);
void				hex_print(t_string *ts, int c);
void				int_print(t_string *ts);
const char			*one_simple_print(t_string *ts, const char *input_str);
void				percent_print(t_string *ts, const char **input_str);
const char			*print_from_input(t_string *ts, const char *input_str, \
va_list *arg_ptr);
void				print_multi_char(t_string *ts, int nb, char c);
void				print_plus_or_minus(t_string *ts);
void				ptr_print(t_string *ts);
void				reset_precision(t_string *ts);
void				reset_struct(t_string *ts);
const char			*save_width(t_string *ts, const char *input_str);
void				simple_print(t_string *ts, char *input_str);
void				simple_n_print(t_string *ts, char *input_str, int n);
void				str_print(t_string *ts);
void				u_int_print(t_string *ts);

#endif
