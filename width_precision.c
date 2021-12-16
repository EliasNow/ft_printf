/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 05:12:25 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/14 20:54:55 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

const char			*save_width(t_string *ts, const char *input_str)
{
	char *ptr;
	char *tmp;

	ptr = (char *)input_str;
	tmp = NULL;
	if (ft_isdigit(*input_str))
	{
		while (ft_isdigit(*input_str))
			input_str++;
		tmp = ft_substr(ptr, 0, (input_str - ptr + 1));
		if (tmp == NULL)
			ts->error = 1;
		else
		{
			ts->width = ft_atoi(tmp);
			free(tmp);
		}
	}
	return (input_str);
}

static const char	*dot_finder(t_string *ts, const char *input_str)
{
	if (*input_str == '.')
	{
		ts->flags->dot++;
		input_str++;
	}
	return (input_str);
}

static const char	*find_precision(t_string *ts, const char *input_str, \
							va_list *arg_ptr)
{
	const char	*ptr;
	char		*tmp;

	input_str = dot_finder(ts, input_str);
	ptr = input_str;
	if (ft_isdigit(*input_str))
	{
		while (ft_isdigit(*input_str))
			input_str++;
		tmp = ft_substr(ptr, 0, (input_str - ptr + 1));
		ts->error = (tmp == NULL) ? 1 : 0;
		if (ts->error == 0)
		{
			ts->flags->precision = ft_atoi(tmp);
			free(tmp);
		}
	}
	else if (ts->flags->dot == 1 && *input_str == '*')
	{
		ts->flags->precision = va_arg(*arg_ptr, int);
		input_str++;
	}
	reset_precision(ts);
	return (*input_str && set_check(*input_str, "ncspdiuxX%") ? \
	input_str : NULL);
}

static const char	*loop_flags(t_string *ts, const char *input_str)
{
	while (set_check(*input_str, "+ 0-#"))
	{
		if (*input_str == '+')
			ts->flags->plus++;
		else if (*input_str == '0')
			ts->flags->zero++;
		else if (*input_str == ' ')
			ts->flags->inv_plus++;
		else if (*input_str == '-')
			ts->flags->left_justify = 1;
		else if (*input_str == '#')
			ts->flags->hash++;
		input_str++;
	}
	return (input_str);
}

const char			*find_width(t_string *ts, const char *input_str, \
					va_list *arg_ptr)
{
	if (set_check(*input_str, "+ 0-*#"))
	{
		input_str = loop_flags(ts, input_str);
		if (*input_str == '*')
		{
			ts->width = va_arg(*arg_ptr, int);
			while (*input_str == '*')
				input_str++;
		}
		else if (ft_isdigit(*input_str) == 1)
			input_str = save_width(ts, input_str);
	}
	else if (ft_isdigit(*input_str) == 1)
		input_str = save_width(ts, input_str);
	if (ts->width < 0)
	{
		ts->width = (ts->width == INT_MIN) ? INT_MAX : ts->width * -1;
		ts->flags->left_justify = 1;
	}
	if (ts->flags->zero && ts->flags->left_justify)
		ts->flags->zero = 0;
	if (*input_str != '%')
		input_str = find_precision(ts, input_str, arg_ptr);
	return (input_str);
}
