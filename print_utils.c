/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 03:01:19 by anijssen      #+#    #+#                 */
/*   Updated: 2020/01/14 06:42:03 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		caps_simple_print(t_string *ts, char *input_str)
{
	char c;

	while (*input_str)
	{
		c = ft_toupper(*input_str);
		write(1, &c, 1);
		ts->n++;
		input_str++;
	}
}

const char	*one_simple_print(t_string *ts, const char *input_str)
{
	if (*input_str != '\0')
	{
		write(1, &(*input_str), 1);
		ts->n++;
		input_str++;
	}
	return (input_str);
}

void		simple_print(t_string *ts, char *input_str)
{
	while (*input_str)
	{
		write(1, &(*input_str), 1);
		ts->n++;
		input_str++;
	}
}

void		simple_n_print(t_string *ts, char *input_str, int n)
{
	int i;

	i = 0;
	while (*input_str && i < n)
	{
		write(1, &(*input_str), 1);
		ts->n++;
		input_str++;
		i++;
	}
}

void		print_multi_char(t_string *ts, int nb, char c)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		ts->n++;
		i++;
	}
}
