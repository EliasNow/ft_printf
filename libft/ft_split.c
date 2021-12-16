/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 20:18:32 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/19 01:15:06 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*parse_and_trim_str(char *dst, char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c && c != '\0')
		s++;
	while (*s)
	{
		if (*s != c || (*s == c && *(s + 1) != c && *(s + 1) != '\0'))
		{
			dst[i] = *s;
			i++;
			s++;
		}
		if ((*s == c && *(s + 1) == c) || (*s == c && *(s + 1) == '\0'))
			s++;
	}
	dst[i] = '\0';
	return (dst);
}

static size_t	nb_of_str(char *s, char c)
{
	size_t	nb;

	if (*s == 0)
		return (0);
	nb = 1;
	while (*s)
	{
		if (*s == c)
			nb++;
		s++;
	}
	return (nb);
}

static void		free_arr(char **arr, size_t j)
{
	while (j > 0)
	{
		free(arr[j - 1]);
		j--;
	}
	free(arr);
}

static char		**mk_and_fill_arr(char *s, char c, size_t nb)
{
	char	**z;
	char	*ptr;
	size_t	j;

	z = (char **)malloc(sizeof(char *) * (nb + 1));
	if (z == 0)
		return (NULL);
	j = 0;
	while (j < nb)
	{
		ptr = ft_strchr(s, (int)c);
		if (ptr)
			z[j] = ft_substr(s, 0, (ptr - s));
		if (!ptr)
			z[j] = ft_substr(s, 0, ft_strlen(s));
		if (z[j] == 0)
			free_arr(z, j);
		s = (ptr + 1);
		j++;
	}
	z[nb] = NULL;
	return (z);
}

char			**ft_split(char const *s, char c)
{
	char	**fz;
	size_t	len;
	char	*trs;
	size_t	nb;

	len = ft_strlen(s);
	trs = (char *)malloc(sizeof(char) * (len + 1));
	if (trs == 0)
		return (NULL);
	trs = parse_and_trim_str(trs, (char *)s, c);
	nb = nb_of_str(trs, c);
	fz = mk_and_fill_arr(trs, c, nb);
	free(trs);
	return (fz);
}
