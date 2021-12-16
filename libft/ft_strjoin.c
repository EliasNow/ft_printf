/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 17:21:00 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 07:11:33 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*new;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	new = malloc(l1 + l2 + 1);
	if (new == 0)
		return (0);
	res = new;
	while (*s1 != '\0')
	{
		*new = *s1;
		new++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*new = *s2;
		new++;
		s2++;
	}
	*new = '\0';
	return (res);
}
