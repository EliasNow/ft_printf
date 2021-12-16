/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_conversions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:32:09 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/18 15:58:39 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		hex_hash_print(t_string *ts, int c)
{
	if (ts->flags->hash && *ts->str != '0' && *ts->str != '\0')
	{
		if (c == 'x')
			simple_print(ts, "0x");
		else if (c == 'X')
			simple_print(ts, "0X");
	}
}

void			hex_print(t_string *ts, int c)
{
	calc_hex_padding(ts);
	if (ts->flags->hash && *ts->str != '\0')
		ts->field_padding -= 2;
	if (ts->flags->left_justify == 0)
	{
		if (ts->flags->zero > 0 && ts->width <= ts->flags->precision)
			print_multi_char(ts, ts->field_padding, '0');
		if (ts->flags->dot == 0 && ts->flags->zero > 0 && ts->flags->plus == 0)
			print_multi_char(ts, ts->field_padding, '0');
		else
			print_multi_char(ts, ts->field_padding, ' ');
		hex_hash_print(ts, c);
	}
	if (ts->flags->hash && ts->flags->left_justify)
		hex_hash_print(ts, c);
	print_multi_char(ts, ts->nb_padding, '0');
	if (ts->len == 0 && ts->flags->dot == 0)
		print_multi_char(ts, 1, '0');
	(c == 'x') ? simple_print(ts, ts->str) : caps_simple_print(ts, ts->str);
	if (ts->flags->left_justify == 1)
		print_multi_char(ts, ts->field_padding, ' ');
}

static void		ptr_print_left_justified(t_string *ts)
{
	simple_print(ts, "0x");
	print_multi_char(ts, ts->nb_padding, '0');
	if (ts->len == 0 && ts->flags->dot && ts->flags->precision \
			&& ts->nb_padding == 0)
		print_multi_char(ts, 1, '0');
	if (ts->len == 0 && ts->flags->dot == 0)
		print_multi_char(ts, 1, '0');
	if (!(ts->len == 0))
		simple_print(ts, ts->str);
	print_multi_char(ts, ts->field_padding, ' ');
}

void			ptr_print(t_string *ts)
{
	calc_hex_padding(ts);
	if (ts->field_padding > 0 && ts->width > (int)ts->len)
		ts->field_padding -= 2;
	if (ts->flags->left_justify == 1)
		ptr_print_left_justified(ts);
	else if (ts->flags->left_justify == 0)
	{
		if (!((ts->flags->zero > 0 && ts->width <= ts->flags->precision) || \
					(ts->flags->dot == 0 && ts->flags->zero > 0)))
			print_multi_char(ts, ts->field_padding, ' ');
		simple_print(ts, "0x");
		print_multi_char(ts, ts->nb_padding, '0');
		if (ts->len == 0 && ts->flags->dot == 0)
			print_multi_char(ts, 1, '0');
		if (!(ts->len == 0))
			simple_print(ts, ts->str);
		if (ts->flags->zero > 0 && ts->width <= ts->flags->precision)
			print_multi_char(ts, ts->field_padding, '0');
		if (ts->flags->dot == 0 && ts->flags->zero > 0)
			print_multi_char(ts, ts->field_padding, '0');
	}
}

void			u_int_print(t_string *ts)
{
	calc_u_int_padding(ts);
	if (ts->flags->left_justify == 0)
	{
		if (ts->flags->zero > 0 && (ts->flags->precision <= (int)ts->len) \
		&& ts->flags->dot == 1)
			print_multi_char(ts, ts->field_padding, ' ');
		else if (ts->flags->zero > 0 && ts->flags->plus == 0 \
		&& ts->nb_padding == 0)
			print_multi_char(ts, ts->field_padding, '0');
		else
			print_multi_char(ts, ts->field_padding, ' ');
	}
	print_multi_char(ts, ts->nb_padding, '0');
	simple_print(ts, ts->str);
	if (ts->len == 0 && ts->flags->dot == 0)
		print_multi_char(ts, 1, '0');
	if (ts->flags->left_justify == 1)
		print_multi_char(ts, ts->field_padding, ' ');
}
