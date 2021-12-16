/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:54:02 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/18 04:12:46 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	len;
	size_t	i;

	s = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (dstsize > 1 && src[i])
	{
		dst[i] = s[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (len);
}
