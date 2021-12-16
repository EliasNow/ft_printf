/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <anijssen@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 18:49:42 by anijssen      #+#    #+#                 */
/*   Updated: 2020/02/01 09:10:49 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_checker(char *base)
{
	int		dec;
	int		hex;
	int		oct;

	dec = 0;
	hex = 0;
	oct = 0;
	dec = ft_strncmp(base, "dec", 3);
	hex = ft_strncmp(base, "hex", 3);
	oct = ft_strncmp(base, "oct", 3);
	if (dec != 0 && hex != 0 && oct != 0)
		return (-1);
	if (oct == 0)
		return (8);
	return (dec == 0 ? 10 : 16);
}

char		*ft_itoa_base(long input, char *base)
{
	static const char	*find_hex = "0123456789abcdef";
	char				*str;
	int					i;
	int					b;

	i = 0;
	str = (char *)malloc(sizeof(char) * (12));
	if (!base || str == NULL || base_checker(base) == -1)
		return (NULL);
	b = base_checker(base);
	while (input > 0)
	{
		if (b == 16)
			str[i] = find_hex[input % b];
		else
			str[i] = input % b + '0';
		input = input / b;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
