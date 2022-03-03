/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritetwo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:53:15 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/19 16:53:22 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			where_is_sprite(t_cub *cub)
{
	int i;
	int j;
	int coll;

	i = 0;
	coll = 0;
	while (cub->p.map[i] != NULL)
	{
		j = 0;
		while (cub->p.map[i][j] != '\0')
		{
			if (cub->p.map[i][j] == 'B')
			{
				cub->x[coll] = j + 0.5;
				cub->y[coll] = i + 0.5;
				coll++;
			}
			++j;
		}
		++i;
	}
}

int				sprites_count(t_cub *cub)
{
	int i;
	int j;
	int coll;

	i = 0;
	coll = 0;
	while (cub->p.map[i] != NULL)
	{
		j = 0;
		while (cub->p.map[i][j] != '\0')
		{
			if (cub->p.map[i][j] == 'B')
				coll++;
			++j;
		}
		++i;
	}
	return (coll);
}

static	void	reverse_sprite(t_cub *cub, int *j)
{
	float tmp;

	tmp = cub->dist[*j - 1];
	cub->dist[*j - 1] = cub->dist[*j];
	cub->dist[*j] = tmp;
	tmp = cub->x[*j - 1];
	cub->x[*j - 1] = cub->x[*j];
	cub->x[*j] = tmp;
	tmp = cub->y[*j - 1];
	cub->y[*j - 1] = cub->y[*j];
	cub->y[*j] = tmp;
}

static	void	sort_distance(t_cub *cub)
{
	int i;
	int j;

	i = 1;
	while (i < cub->p.coll_sprite)
	{
		j = i;
		while ((int)cub->dist[j] > (int)cub->dist[j - 1] && j != 0)
		{
			reverse_sprite(cub, &j);
			--j;
		}
		++i;
	}
}

void			sort_sprite(t_cub *cub)
{
	int i;

	i = -1;
	while (++i < cub->p.coll_sprite)
	{
		cub->dist[i] = ((cub->plr.x - cub->x[i])
		* (cub->plr.x - cub->x[i])
		+ (cub->plr.y - cub->y[i]) * (cub->plr.y - cub->y[i]));
	}
	if (cub->p.coll_sprite > 1)
		sort_distance(cub);
}
