/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 20:45:19 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/19 04:03:14 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	int				i;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	if (n >= 1)
	{
		while ((n > 1) && ps1[i] == ps2[i])
		{
			i++;
			n--;
		}
		return (ps1[i] - ps2[i]);
	}
	return (ps1[i] - ps2[i]);
}
