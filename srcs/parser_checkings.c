/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checkings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:45:33 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/24 13:51:56 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_all(t_cub *cub)
{
	if (cub->p.res_l == 0 || cub->p.res_w == 0
	|| ft_strlen(cub->p.north_texture) == 0
	|| ft_strlen(cub->p.south_texture) == 0
	|| ft_strlen(cub->p.west_texture) == 0
	|| ft_strlen(cub->p.east_texture) == 0 || ft_strlen(cub->p.spr_texture) == 0
	|| cub->p.floor_flag != 1 || cub->p.ceiling_flag != 1)
	{
		ft_putstr_fd("Error\nWas set not all edificatory or ", 1);
		error("there are repetitions", cub);
	}
}

void	check_space_in_rgb(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			error("Error\nA space was found in color", cub);
		++i;
	}
}

void	check_ceiling(t_cub *cub)
{
	if ((cub->p.ceiling_r > 255 || cub->p.ceiling_r < 0) ||
	(cub->p.ceiling_g > 255 || cub->p.ceiling_g < 0) ||
	(cub->p.ceiling_b > 255 || cub->p.ceiling_b < 0))
		error("Error\nNot a valid ceilling color", cub);
	cub->p.ceiling_flag = 1;
}

void	check_floor(t_cub *cub)
{
	if ((cub->p.floor_r > 255 || cub->p.floor_r < 0) ||
	(cub->p.floor_g > 255 || cub->p.floor_g < 0) ||
	(cub->p.floor_b > 255 || cub->p.floor_b < 0))
		error("Error\nNot a valid floor color", cub);
	cub->p.floor_flag = 1;
}

void	check_resolution(t_cub *cub)
{
	int width;
	int height;

	mlx_get_screen_size(&cub->mlx, &width, &height);
	if (cub->p.res_w < 0 || cub->p.res_l < 0)
		error("Error\nNot a valid resolution", cub);
	if (cub->p.res_w > width || cub->p.res_l > height)
	{
		cub->p.res_w = width;
		cub->p.res_l = height;
	}
}

