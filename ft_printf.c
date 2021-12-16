/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 03:31:43 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/13 22:05:05 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

static void		jumps_to_print(t_string *ts, int c)
{
	if (!ts->error)
	{
		if (c == 'i' || c == 'd')
			int_print(ts);
		else if (c == 'p')
			ptr_print(ts);
		else if (c == 's')
			str_print(ts);
		else if (c == 'u')
			u_int_print(ts);
		else if (c == 'x' || c == 'X')
			hex_print(ts, c);
	}
}

char	*ft_ultoa_super(unsigned long u, int base)
{
	static const char	*find_hex = "0123456789abcdef";
	char				*str;
	int					i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (11));
	if (str == NULL)
		return (NULL);
	while (u > 0)
	{
		if (base == 16)
			str[i] = find_hex[u % base];
		else
			str[i] = (u % base) + '0';
		u = u / base;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

static void		null_check(t_string *ts, char *input_str)
{
	if (ts->str == NULL && *input_str != '%')
	{
		if (*input_str == 's')
		{
			ts->str = ft_strdup("(null)");
			ts->free = 1;
			if (ts->str == NULL)
				ts->error = 1;
		}
	}
}

static int		is_conversion(t_string *ts, char *input_str, va_list *arg_ptr)
{
	if (*input_str == 'c')
		c_print(ts, arg_ptr);
	else if (*input_str == '%')
		percent_print(ts, (const char **)&input_str);
	else if (*input_str == 'p')
		ts->str = ft_ultoa_base(((unsigned long)va_arg(*arg_ptr, void *)), 16);
	else if (*input_str == 's')
		ts->str = va_arg(*arg_ptr, char *);
	else if (*input_str == 'i' || *input_str == 'd')
		ts->str = ft_itoa(va_arg(*arg_ptr, int));
	else if (*input_str == 'n')
		*(va_arg(*arg_ptr, int *)) = ts->n;
	else if (*input_str == 'u')
		ts->str = ft_ultoa(va_arg(*arg_ptr, unsigned int));
	else if (*input_str == 'x' || *input_str == 'X')
		ts->str = ft_ultoa_base(va_arg(*arg_ptr, unsigned int), 16);
	null_check(ts, input_str);
	jumps_to_print(ts, *input_str);
	if (*input_str != 's')
		free(ts->str);
	return ((ts->error) ? 0 : 1);
}

static void		printf_recursive(t_string *ts, const char *input_str, \
		va_list *arg_ptr)
{
	int				success;

	success = 0;
	input_str = print_from_input(ts, input_str, arg_ptr);
	while (input_str && *input_str && ts->skip_percent)
	{
		reset_struct(ts);
		input_str = print_from_input(ts, input_str, arg_ptr);
	}
	if (input_str && !ts->error)
	{
		success = is_conversion(ts, (char *)input_str, arg_ptr);
		if (success && !ts->error)
		{
			if (*input_str)
				input_str++;
			reset_struct(ts);
			printf_recursive(ts, input_str, arg_ptr);
		}
	}
}

int				ft_printf(const char *input_str, ...)
{
	va_list		arg_ptr;
	t_string	ts;
	t_flags		flags;

	va_start(arg_ptr, input_str);
	if (input_str == NULL)
		return (-1);
	ts.flags = &flags;
	flags.next = NULL;
	ts.n = 0;
	reset_struct(&ts);
	printf_recursive(&ts, input_str, &arg_ptr);
	va_end(arg_ptr);
	if (ts.error)
		return (-1);
	return (ts.n);
}
