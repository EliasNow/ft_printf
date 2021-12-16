/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 01:13:53 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/16 18:23:13 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*a;
	const char	*n;

	if (needle[0] == 0)
		return ((char *)haystack);
	n = needle;
	while ((*haystack) && (*haystack != *needle) && (len > 0))
	{
		haystack++;
		len--;
	}
	a = haystack;
	while ((*haystack == *needle) && (len > 0))
	{
		haystack++;
		needle++;
		len--;
		if (*needle == '\0')
			return ((char *)a);
	}
	if ((*needle != '\0') && (*needle != *n))
		return (ft_strnstr(haystack, n, len));
	return (0);
}
