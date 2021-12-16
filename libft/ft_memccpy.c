/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:48:13 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 07:01:10 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		p2[i] = p1[i];
		if (p1[i] == (unsigned char)c)
			return (p2 + i + 1);
		i++;
	}
	return (NULL);
}
