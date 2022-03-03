/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:10:21 by akhachat          #+#    #+#             */
/*   Updated: 2021/02/07 16:18:24 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lost;
	t_list	*lom;

	if (!f || !del)
		return (NULL);
	lost = NULL;
	while (lst)
	{
		if (!(lom = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lost, del);
			return (NULL);
		}
		ft_lstadd_back(&lost, lom);
		lst = lst->next;
	}
	return (lost);
}
