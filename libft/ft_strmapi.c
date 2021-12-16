/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 03:44:38 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/12 06:45:04 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		len;
	char		*ptr;

	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (NULL);
	ptr[len] = '\0';
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
