/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 00:49:25 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/18 19:26:50 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*p1;
	const char	*p2;

	p1 = s;
	p2 = (char *)&c;
	if (*p1 == (char)c)
		p2 = p1;
	while (*p1)
	{
		p1++;
		if (*p1 == (char)c)
			p2 = p1;
	}
	if ((char)c == '\0')
		return ((char *)p1);
	else if (p2 == (char *)&c)
		return (NULL);
	return ((char *)p2);
}
