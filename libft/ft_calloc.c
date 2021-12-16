/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 17:54:01 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 07:35:53 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*m;

	m = malloc(count * size);
	if ((char *)m)
	{
		ft_bzero(m, count * size);
		return (m);
	}
	else
		return (NULL);
}
