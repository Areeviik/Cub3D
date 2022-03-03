/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:16:54 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/21 16:17:12 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			get_floor(char *tmp, t_cub *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.floor_r = ft_atoi(tmp);
	else
		error("Error\nNot set floor_r", cub);
	tmp += ft_digit_num(cub->p.floor_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.floor_g = ft_atoi(tmp);
	else
		error("Error\nNot set floor_g", cub);
	tmp += ft_digit_num(cub->p.floor_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.floor_b = ft_atoi(tmp);
	else
		error("Error\nNot set floor_b", cub);
}

void			get_ceiling(char *tmp, t_cub *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.ceiling_r = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_r", cub);
	tmp += ft_digit_num(cub->p.ceiling_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.ceiling_g = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_g", cub);
	tmp += ft_digit_num(cub->p.ceiling_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.ceiling_b = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_b", cub);
}

void			space_in_map(char *str, t_cub *cub)
{
	int i;

	i = 0;
	{
		if (str[i] != ' ')
			return ;
		++i;
	}
	ft_putstr_fd("Error\nAn empty line", 1);
	error("with spaces at the end of the map", cub);
}

static	void	check_symbols_map_two(int *flag, int *i, int *j, t_cub *cub)
{
	if (cub->p.map[*i][*j] == 'N' || cub->p.map[*i][*j] == 'S'
	|| cub->p.map[*i][*j] == 'E' || cub->p.map[*i][*j] == 'W')
	{
		if (*flag == 0)
		{
			*flag = 1;
			cub->p.player = &cub->p.map[*i][*j];
			cub->p.player_y = *i;
			cub->p.player_x = *j;
		}
		else
			error("Error\nMore than one player detected", cub);
	}
}

void			check_symbols_map(int size, t_cub *cub)
{
	int i;
	int j;
	int flag;

	i = -1;
	flag = 0;
	while (++i != size)
	{
		j = 0;
		while (cub->p.map[i][j] != '\0')
		{
			check_symbols_map_two(&flag, &i, &j, cub);
			if (cub->p.map[i][j] == ' ' || cub->p.map[i][j] == '0'
			|| cub->p.map[i][j] == '1' || cub->p.map[i][j] == '2'
			|| cub->p.map[i][j] == 'N' || cub->p.map[i][j] == 'S'
			|| cub->p.map[i][j] == 'E' || cub->p.map[i][j] == 'W')
				++j;
			else
				error("Error\nWrong symbol in the map", cub);
		}
	}
	if (flag == 0)
		error("Error\nNo player detected", cub);
}
