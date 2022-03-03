/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:25:31 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/20 18:25:38 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	set_player_direction_two(t_cub *cub)
{
	if (cub->plr.dir_symbol == 'W')
	{
		cub->plr.dir_y = 0;
		cub->plr.dir_x = -1;
		cub->plr.plane_y = -0.66;
		cub->plr.plane_x = 0;
	}
	else if (cub->plr.dir_symbol == 'E')
	{
		cub->plr.dir_y = 0;
		cub->plr.dir_x = 1;
		cub->plr.plane_y = 0.66;
		cub->plr.plane_x = 0;
	}
}

void			set_player_direction(t_cub *cub)
{
	if (cub->plr.dir_symbol == 'N')
	{
		cub->plr.dir_y = -1;
		cub->plr.dir_x = 0;
		cub->plr.plane_y = 0;
		cub->plr.plane_x = 0.66;
	}
	else if (cub->plr.dir_symbol == 'S')
	{
		cub->plr.dir_y = 1;
		cub->plr.dir_x = 0;
		cub->plr.plane_y = 0;
		cub->plr.plane_x = -0.66;
	}
	else
		set_player_direction_two(cub);
}