/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 21:44:22 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/01 10:33:00 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*begin;
	char	*end;
	int		len;

	begin = str;
	len = ft_strlen(str);
	end = str + len - 1;
	while (str < end)
	{
		ft_swap(&(*str), &(*end));
		str++;
		end--;
	}
	return (begin);
}
