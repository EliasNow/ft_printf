/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 18:27:08 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/20 01:14:12 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	sub = (char *)malloc(sizeof(char) * len + 1);
	if (sub == 0)
		return (NULL);
	i = start;
	j = 0;
	while (len > 0)
	{
		sub[j] = s[i];
		i++;
		j++;
		len--;
	}
	sub[j] = '\0';
	return (sub);
}
