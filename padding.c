/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 01:46:32 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/04 23:59:14 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calc_hex_padding(t_string *ts)
{
	ts->len = ft_strlen(ts->str);
	if (ts->flags->dot == 1)
	{
		if (ts->flags->precision < (int)ts->len)
			ts->flags->precision = (int)ts->len;
		if (ts->flags->precision > (int)ts->len)
			ts->nb_padding = ts->flags->precision - ts->len;
		if (ts->width > ts->flags->precision)
			ts->field_padding = ts->width - ts->flags->precision;
	}
	if (ts->flags->dot == 0)
	{
		if (ts->width > (int)ts->len)
			ts->field_padding = ts->width - (int)ts->len;
		if (ts->len == 0 && ts->field_padding > 0)
			ts->field_padding--;
	}
}

void	calc_str_padding(t_string *ts)
{
	ts->len = ft_strlen(ts->str);
	if (ts->flags->precision > ts->width && ts->width > (int)ts->len)
		ts->flags->dot = 0;
	if (ts->flags->precision > ts->width && ts->width > (int)ts->len)
		ts->flags->precision = 0;
	if (ts->flags->precision > (int)ts->len)
		ts->nb_padding = ts->flags->precision - (int)ts->len;
	if (ts->width > (int)ts->len || ts->width > ts->flags->precision)
	{
		if (ts->flags->dot == 0)
			ts->field_padding = ts->width - (int)ts->len;
		if (ts->flags->dot == 1)
		{
			ts->field_padding = ts->width - ts->flags->precision;
			if (ts->flags->precision > (int)ts->len)
				ts->field_padding += ts->flags->precision - (int)ts->len;
		}
	}
	if (ts->flags->dot == 1)
	{
		if (ts->flags->precision > ts->width)
			ts->field_padding = 0;
	}
	if (ts->len == 0)
		ts->field_padding = ts->width;
}

void	calc_u_int_padding(t_string *ts)
{
	ts->len = ft_strlen(ts->str);
	if (ts->flags->dot == 1)
	{
		if (ts->flags->precision > (int)ts->len)
			ts->nb_padding = ts->flags->precision - ts->len;
		if (ts->flags->precision < (int)ts->len)
			ts->flags->precision = (int)ts->len;
		if (ts->width > ts->flags->precision)
			ts->field_padding = ts->width - ts->flags->precision;
		if (ts->flags->precision > ts->width)
			ts->field_padding = 0;
	}
	else
	{
		if (ts->width > (int)ts->len)
			ts->field_padding = ts->width - (int)ts->len;
		if (ts->len == 0)
			ts->field_padding--;
	}
}
