/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 01:38:46 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/01 09:11:10 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long u, int base)
{
	static const char	*find_hex = "0123456789abcdef";
	char				*str;
	int					i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (20));
	if (str == NULL)
		return (NULL);
	while (u > 0)
	{
		if (base == 16)
			str[i] = find_hex[u % base];
		else
			str[i] = (u % base) + '0';
		u = u / base;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
