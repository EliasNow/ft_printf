/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 06:29:01 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/10 19:37:22 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		skip_percent(t_string *ts, const char **input_str)
{
	if (**input_str == '%' && *(*input_str + 1) == '%')
	{
		(*input_str)++;
		one_simple_print(ts, *input_str);
		(*input_str)++;
		ts->skip_percent = 1;
	}
}

const char		*print_from_input(t_string *ts, const char *input_str, \
		va_list *arg_ptr)
{
	while (*input_str && *input_str != '%')
		input_str = one_simple_print(ts, input_str);
	if (*input_str == '%')
	{
		if (*input_str == '%' && *(input_str + 1) == '%')
		{
			skip_percent(ts, &input_str);
			return (input_str);
		}
		input_str++;
		input_str = find_width(ts, input_str, arg_ptr);
		if (input_str == NULL || *input_str == '\0')
			return (NULL);
		if (*input_str != '\0')
			return ((char *)input_str);
	}
	return (NULL);
}
