/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 21:58:01 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 12:13:20 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*c;

	c = (unsigned char *)s;
	while (n > 0)
	{
		c[n - 1] = 0;
		n--;
	}
}
