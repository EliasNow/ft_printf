/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_padding.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 05:31:40 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/13 21:35:12 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		remove_zero(t_string *ts)
{
	if (*ts->str == '0' && ts->flags->dot && ts->flags->precision == 0)
	{
		free(ts->str);
		ts->str = ft_strdup("");
		ts->error = (ts->str == NULL) ? 1 : 0;
		return ;
	}
	if (*ts->str == '0' && ts->width && ts->flags->precision == 0)
	{
		if (ts->flags->dot && ts->flags->precision == 0)
		{
			free(ts->str);
			ts->str = ft_strdup("");
			ts->error = (ts->str == NULL) ? 1 : 0;
			return ;
		}
		if (ts->flags->zero)
		{
			free(ts->str);
			ts->str = ft_strdup("");
			ts->error = (ts->str == NULL) ? 1 : 0;
		}
	}
}

static void		calc_int_padding_precision_edge(t_string *ts)
{
	if (*ts->str == '-' && ts->edge == 0 && \
			(int)ts->len == ts->flags->precision)
	{
		ts->nb_padding++;
		if (ts->field_padding)
			ts->field_padding--;
	}
}

static void		calc_int_padding_precision(t_string *ts)
{
	if (ts->flags->dot == 1)
	{
		if (ts->flags->precision > (int)ts->len)
			ts->nb_padding = ts->flags->precision - (int)ts->len;
		if (ts->flags->precision < (int)ts->len)
		{
			ts->edge = 1;
			ts->flags->precision = (int)ts->len;
		}
		if (ts->width > ts->flags->precision)
			ts->field_padding = ts->width - ts->flags->precision;
		if ((ts->flags->plus || ts->flags->inv_plus) \
				&& ts->field_padding && *ts->str != '-')
			ts->field_padding--;
		if (*ts->str == '-' && ts->nb_padding)
		{
			ts->nb_padding++;
			if (ts->field_padding)
				ts->field_padding--;
		}
	}
	calc_int_padding_precision_edge(ts);
}

void			calc_int_padding(t_string *ts)
{
	remove_zero(ts);
	if (!ts->error)
	{
		ts->len = ft_strlen(ts->str);
		calc_int_padding_precision(ts);
		if (ts->flags->dot == 0)
		{
			if (ts->width > (int)ts->len)
				ts->field_padding = ts->width - (int)ts->len;
			if (ts->flags->inv_plus && ts->flags->left_justify \
			&& *ts->str != '-')
				ts->field_padding--;
			if (ts->flags->inv_plus && *ts->str != '-' && *ts->str != '0' && \
					!ts->flags->left_justify && ts->field_padding \
					&& !ts->flags->plus && !ts->flags->zero)
				ts->field_padding--;
			if (ts->field_padding && ts->flags->plus)
			{
				if (!ts->flags->zero && *ts->str != '0')
					ts->field_padding--;
			}
			if (ts->field_padding && ts->flags->plus && *ts->str == '\0')
				ts->field_padding--;
		}
	}
}
