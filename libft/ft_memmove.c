/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:39:01 by akhachat          #+#    #+#             */
/*   Updated: 2021/02/07 18:18:41 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t						i;
	unsigned char				*s1;
	unsigned const char			*s2;
	unsigned char				buff[len];

	s1 = dst;
	s2 = src;
	i = 0;
	while (i < len)
	{
		buff[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		s1[i] = buff[i];
		i++;
	}
	return (s1);
}
