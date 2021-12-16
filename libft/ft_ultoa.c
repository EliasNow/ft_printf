/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 01:38:46 by anijssen      #+#    #+#                 */
/*   Updated: 2020/01/07 20:53:15 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long u)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (11));
	if (str == NULL)
		return (NULL);
	while (u > 0)
	{
		str[i] = (u % 10) + '0';
		u = u / 10;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
