/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utilsthree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:19:49 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/15 15:21:28 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error(char *str, t_cub *cub)
{
	(void)cub;
	ft_putendl_fd(str, 1);
	exit(1);
}

int		close_win(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->mlx_window);
	system("killall afplay");
	exit(0);
	return (0);
}

void	free_map(t_list **lst)
{
	t_list *p;

	while (*lst)
	{
		p = (*lst)->next;
		free(*lst);
		*lst = p;
	}
	*lst = NULL;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int		my_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

