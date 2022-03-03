/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:05:06 by akhachat          #+#    #+#             */
/*   Updated: 2021/02/06 16:13:19 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *cont)
{
	t_list *mek;

	if (!(mek = malloc(sizeof(t_list))))
		return (NULL);
	mek->content = cont;
	mek->next = NULL;
	return (mek);
}
