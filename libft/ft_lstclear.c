/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anijssen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 02:41:01 by anijssen      #+#    #+#                 */
/*   Updated: 2019/11/18 05:25:37 by anijssen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*tmp;

	while (*lst)
	{
		tmp = (*lst);
		*lst = tmp->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
