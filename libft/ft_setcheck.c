/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setcheck.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:02:59 by anijssen      #+#    #+#                 */
/*   Updated: 2020/01/07 13:07:40 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
