/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 19:28:05 by anijssen      #+#    #+#                 */
/*   Updated: 2020/01/28 22:01:40 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;
	char	*t;

	beg = 0;
	end = ft_strlen(s1);
	while (set_check(s1[beg], set) == 1 && s1[beg] != '\0')
		beg++;
	if (s1[beg] == '\0')
		return (ft_strdup(""));
	while ((set_check(s1[end - 1], set) == 1) && (end - 1 > 0))
		end--;
	end = end - beg;
	t = (char *)malloc(end + 1);
	if (t == 0)
		return (t);
	t[end] = '\0';
	return ((char *)ft_memcpy(t, (s1 + beg), end));
}
