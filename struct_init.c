/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 21:46:54 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/05 12:48:35 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_precision(t_string *ts)
{
	if (ts->flags->precision < 0)
	{
		ts->flags->precision = 0;
		ts->flags->dot = 0;
	}
}

void		reset_struct(t_string *ts)
{
	ts->edge = 0;
	ts->error = 0;
	ts->free = 0;
	ts->len = 0;
	ts->skip_percent = 0;
	ts->str = NULL;
	ts->neg = 0;
	ts->width = 0;
	ts->field_padding = 0;
	ts->field_printed = 0;
	ts->nb_padding = 0;
	ts->nb_printed = 0;
	ts->flags->asterisk = 0;
	ts->flags->dot = 0;
	ts->flags->hash = 0;
	ts->flags->left_justify = 0;
	ts->flags->percent = 0;
	ts->flags->plus = 0;
	ts->flags->inv_plus = 0;
	ts->flags->precision = 0;
	ts->flags->zero = 0;
}
