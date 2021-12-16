/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:34:34 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/18 05:04:28 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	dl;
	size_t	sl;
	size_t	i;

	s = (char *)src;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dstsize == 0)
		return (sl);
	i = 0;
	while (i + dl + 1 < dstsize && src[i] != '\0')
	{
		dst[dl + i] = s[i];
		i++;
		if (i == sl)
		{
			dst[dl + i] = '\0';
			return (dl + i);
		}
	}
	dst[dl + i] = '\0';
	if (dstsize < dl)
		dl = dstsize;
	return (sl + dl);
}
