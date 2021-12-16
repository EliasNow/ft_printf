/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_print.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 04:47:38 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/18 15:59:14 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		int_print_helper_pad_worker(t_string *ts)
{
	if (ts->flags->plus == 0 && ts->flags->inv_plus == 0)
	{
		if (ts->flags->zero == 1)
		{
			print_multi_char(ts, ts->field_padding, '0');
			ts->field_printed++;
		}
	}
	else if ((!ts->flags->plus && !ts->flags->inv_plus) && !ts->flags->zero)
	{
		if (*ts->str == '0' || ft_strlen(ts->str) == 0)
			ts->field_padding -= 2;
		print_multi_char(ts, ts->field_padding, ' ');
		ts->field_printed++;
	}
	else if (!ts->field_printed && (*ts->str == '0' || !ts->len) \
			&& !ts->flags->zero)
	{
		ts->field_padding--;
		print_multi_char(ts, ts->field_padding, ' ');
		ts->field_printed++;
	}
}

static void		int_print_helper_extra_pad_worker(t_string *ts)
{
	if (ts->field_printed == 0)
	{
		if (ts->flags->precision == 0 && ts->flags->zero && ts->flags->plus)
		{
			ts->field_padding--;
			ts->nb_padding++;
		}
		else if (ts->len != 0)
		{
			if (ts->flags->inv_plus == 0)
			{
				if (ts->flags->zero)
					print_multi_char(ts, ts->field_padding, '0');
				else
					print_multi_char(ts, ts->field_padding, ' ');
				ts->field_printed++;
			}
		}
	}
}

static void		int_print_helper(t_string *ts)
{
	if (ts->width && !ts->flags->dot && (*ts->str != '-') \
			&& ts->flags->precision <= (int)ts->len)
	{
		int_print_helper_pad_worker(ts);
		int_print_helper_extra_pad_worker(ts);
	}
	if (!ts->flags->left_justify && (!ts->field_printed && !ts->flags->zero))
	{
		print_multi_char(ts, ts->field_padding, ' ');
		ts->field_printed++;
	}
	if (*ts->str == '-' && ts->field_printed == 0 && ts->flags->dot)
	{
		print_multi_char(ts, ts->field_padding, ' ');
		ts->field_printed++;
	}
	if (ts->field_printed == 0 && ts->field_padding && \
			ts->flags->zero && *ts->str != '-')
	{
		if ((ts->field_padding && ts->flags->dot == 0 && ts->flags->zero) == 0)
		{
			print_multi_char(ts, ts->field_padding, ' ');
			ts->field_printed++;
		}
	}
}

static void		int_print_post_sign_helper(t_string *ts)
{
	if (ts->width && !ts->flags->dot && !ts->neg && \
			ts->flags->precision <= (int)ts->len)
	{
		if ((ts->flags->plus || ts->flags->inv_plus) && ts->flags->zero)
		{
			ts->field_padding--;
			print_multi_char(ts, ts->field_padding, '0');
			ts->field_printed++;
		}
	}
	if (ts->nb_padding == 0)
	{
		if (ts->neg == 1 && ts->field_printed == 0)
		{
			print_multi_char(ts, ts->field_padding, '0');
			ts->field_printed++;
		}
	}
}

void			int_print(t_string *ts)
{
	calc_int_padding(ts);
	if (ts->flags->left_justify == 0)
		int_print_helper(ts);
	print_plus_or_minus(ts);
	if (ts->flags->left_justify == 0)
		int_print_post_sign_helper(ts);
	if (ts->nb_printed == 0)
		print_multi_char(ts, ts->nb_padding, '0');
	if (ts->flags->left_justify == 1 && ts->neg == 0)
	{
		if (ts->flags->zero && ts->flags->dot == 0 && ts->field_printed == 0)
			print_multi_char(ts, ts->field_padding, '0');
	}
	if ((*ts->str == '0' && ts->len && !ts->width && ts->flags->dot) == 0)
		(ts->neg) ? simple_print(ts, (ts->str + 1)) : simple_print(ts, ts->str);
	if (*ts->str == '0' && !ts->width && ts->flags->dot \
			&& ts->flags->precision > 0)
		print_multi_char(ts, 1, '0');
	if (*ts->str == '\0' && ts->width && ts->flags->plus)
	{
		if ((ts->flags->dot == 1 && ts->flags->precision == 0) == 0)
			print_multi_char(ts, 1, '0');
	}
	if (ts->flags->left_justify && ts->field_printed == 0)
		print_multi_char(ts, ts->field_padding, ' ');
}
