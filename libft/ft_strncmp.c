/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:24:42 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/19 03:54:31 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n >= 1)
	{
		while ((n > 1) && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		{
			i++;
			n--;
		}
		return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
	}
	else
		return (0);
}
