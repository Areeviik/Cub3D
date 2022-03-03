/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:30:47 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/19 16:30:58 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprite_two(t_cub *cub)
{
	int width;
	int height;

	if (!(cub->t_sprite.img = mlx_xpm_file_to_image(cub->mlx,
									cub->p.spr_texture, &width, &height)))
		error("Error\nNo texture found for the sprite", cub);
	cub->t_sprite.address = mlx_get_data_addr(cub->t_sprite.img,
	&cub->t_sprite.bits_per_pixel, &cub->t_sprite.line_length, &cub->t_sprite.endian);
}

void	get_sprite(t_cub *cub)
{
	int width;
	int height;

	if (!(cub->t_north.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.north_texture, &width, &height)))
		error("Error\nNo texture found for North", cub);
	cub->t_north.address = mlx_get_data_addr(cub->t_north.img, &cub->t_north.bits_per_pixel,
									&cub->t_north.line_length, &cub->t_north.endian);
	if (!(cub->t_south.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.south_texture, &width, &height)))
		error("Error\nNo texture found for the South", cub);
	cub->t_south.address = mlx_get_data_addr(cub->t_south.img, &cub->t_south.bits_per_pixel,
					&cub->t_south.line_length, &cub->t_south.endian);
	if (!(cub->t_west.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.west_texture, &width, &height)))
		error("Error\nNo texture found for the West", cub);
	cub->t_west.address = mlx_get_data_addr(cub->t_west.img, &cub->t_west.bits_per_pixel,
									&cub->t_west.line_length, &cub->t_west.endian);
	if (!(cub->t_east.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.east_texture, &width, &height)))
		error("Error\nNo texture found for the East", cub);
	cub->t_east.address = mlx_get_data_addr(cub->t_east.img, &cub->t_east.bits_per_pixel,
									&cub->t_east.line_length, &cub->t_east.endian);
	get_sprite_two(cub);
}
