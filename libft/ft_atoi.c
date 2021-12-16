/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:01:41 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/19 04:31:06 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

static const char	*ft_skip_wh_space(const char *str)
{
	if (!((*str == '\0') || (*str >= '0' && *str <= '9')))
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || \
		*str == '\v' || *str == '\f' || *str == '\r')
			str++;
	}
	return (str);
}

int					ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	res = 0;
	str = ft_skip_wh_space(str);
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > LLONG_MAX && sign == -1)
			return (0);
		if (res > LLONG_MAX && sign == 1)
			return (-1);
		str++;
	}
	return ((int)res * sign);
}
