/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 06:25:22 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/12 06:28:01 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	int k;

	k = 0;
	if (n < 0)
		k++;
	if (n == 0)
		k++;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		k++;
	}
	return (k);
}

static char	*ft_make_str(int len)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (NULL);
	ptr[len] = '\0';
	return (ptr);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		tmp;

	len = ft_nb_len(n);
	ptr = ft_make_str(len);
	if (ptr == 0)
		return (NULL);
	len--;
	while (n >= 10 || n <= -10)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp = tmp * -1;
		ptr[len] = tmp + '0';
		n = n / 10;
		len--;
	}
	if (n < 0)
	{
		n *= -1;
		ptr[len - 1] = '-';
	}
	ptr[len] = n + '0';
	return (ptr);
}
