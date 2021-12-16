/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 11:31:12 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 04:42:27 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (dst == 0 && src == 0 && n > 0)
		return (dst);
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		p2[i] = p1[i];
		i++;
	}
	return (dst);
}
