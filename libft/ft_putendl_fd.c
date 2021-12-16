/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_endl_fd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 06:46:14 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/13 07:10:04 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
