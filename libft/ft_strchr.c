/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 22:49:07 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/19 02:52:26 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	if (*ptr == (char)c)
		return ((char *)ptr);
	while ((*ptr != '\0') && (*ptr != (char)c))
	{
		ptr++;
		if (*ptr == (char)c)
			return ((char *)ptr);
	}
	return (0);
}
