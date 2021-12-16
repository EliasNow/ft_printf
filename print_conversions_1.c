/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 02:14:34 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/13 21:19:21 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			c_print(t_string *ts, va_list *arg_ptr)
{
	if (ts->flags->left_justify == 0)
		print_multi_char(ts, (ts->width - 1), ' ');
	ft_putchar_fd(va_arg(*arg_ptr, int), 1);
	ts->n++;
	if (ts->flags->left_justify == 1)
		print_multi_char(ts, (ts->width - 1), ' ');
}

void			percent_print(t_string *ts, const char **input_str)
{
	if (**input_str == '%' && ts->width)
	{
		if (ts->flags->left_justify == 0)
		{
			if (ts->flags->zero && ts->width)
				print_multi_char(ts, (ts->width - 1), '0');
			else if (ts->flags->zero == 0 && ts->width)
				print_multi_char(ts, (ts->width - 1), ' ');
		}
		one_simple_print(ts, *input_str);
		(*input_str)++;
		if (ts->flags->left_justify == 1 && ts->width)
			print_multi_char(ts, (ts->width - 1), ' ');
		ts->flags->percent = 1;
	}
	else if (**input_str == '%' && !ts->width)
		one_simple_print(ts, *input_str);
}

void			print_plus_or_minus(t_string *ts)
{
	if (ts->flags->plus > 0 && ts->str[0] != '-')
	{
		ft_putchar_fd('+', 1);
		ts->n++;
	}
	else if (ts->str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		ts->n++;
		ts->neg = 1;
	}
	else if (ts->flags->inv_plus > 0)
	{
		ft_putchar_fd(' ', 1);
		ts->n++;
	}
}

void			str_print(t_string *ts)
{
	calc_str_padding(ts);
	if (ts->flags->left_justify == 0)
		print_multi_char(ts, ts->field_padding, ' ');
	if (ts->flags->dot == 1)
		simple_n_print(ts, ts->str, ts->flags->precision);
	if (ts->flags->dot == 0)
		simple_print(ts, ts->str);
	if (ts->flags->left_justify > 0)
		print_multi_char(ts, ts->field_padding, ' ');
	if (ts->free == 1)
	{
		if (ft_strncmp("(null)", ts->str, 6) == 0)
			free(ts->str);
		ts->str = NULL;
		ts->free = 0;
	}
}
