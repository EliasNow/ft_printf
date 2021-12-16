/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 05:53:35 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 04:54:41 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN -2147483648

void	ft_putnbr_fd(int n, int fd)
{
	if (n == MIN)
	{
		ft_putnbr_fd(n / 10, fd);
		n = 8;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
