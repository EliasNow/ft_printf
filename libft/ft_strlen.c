/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 00:48:54 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 04:53:10 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
