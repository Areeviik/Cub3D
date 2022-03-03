/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:40:33 by akhachat          #+#    #+#             */
/*   Updated: 2021/02/04 16:18:16 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;
	int			i;
	int			one;
	int			two;

	if (!(s1 && s2))
		return (NULL);
	else
		one = ft_strlen(s1);
	two = ft_strlen(s2);
	dest = (char*)malloc(sizeof(char) * (one + two + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		dest[one] = s2[i];
		one++;
	}
	dest[one] = '\0';
	return (dest);
}
