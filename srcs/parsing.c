/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:32:46 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/20 19:32:52 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void			parser_index_three
	(char *line, int id, int index, t_cub *cub)
{
	char *tmp;

	tmp = &line[index];
	if (id == 6)
		cub->p.spr_texture = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 7)
	{
		check_space_in_rgb(tmp, cub);
		get_floor(tmp, cub);
		check_floor(cub);
	}
	else if (id == 8)
	{
		check_space_in_rgb(tmp, cub);
		get_ceiling(tmp, cub);
		check_ceiling(cub);
	}
}

static void			parser_index_two(char *line, int id, int index, t_cub *cub)
{
	char *tmp;

	while (line[index] == ' ' || line[index] == '\t')
		++index;
	tmp = &line[index];
	if (id == 1)
	{
		cub->p.res_w = ft_atoi(tmp);
		tmp += ft_digit_num(cub->p.res_w);
		cub->p.res_l = ft_atoi(tmp);
		check_resolution(cub);
	}
	else if (id == 2)
		cub->p.north_texture = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 3)
		cub->p.south_texture = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 4)
		cub->p.west_texture = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 5)
		cub->p.east_texture = ft_substr(line, index, ft_strlen(tmp));
	else
		parser_index_three(line, id, index, cub);
}

static	void		parser_index(char *line, t_cub *cub)
{
	int index;

	index = 0;
	while (line[index] == ' ' || line[index] == '\t')
		++index;
	if (line[index] == 'R')
		parser_index_two(line, 1, ++index, cub);
	else if (line[index] == 'F')
		parser_index_two(line, 7, ++index, cub);
	else if (line[index] == 'C')
		parser_index_two(line, 8, ++index, cub);
	else if (line[index++] == 'N' && line[index] == 'O')
		parser_index_two(line, 2, ++index, cub);
	else if (line[--index] == 'S' && line[++index] == 'O')
		parser_index_two(line, 3, ++index, cub);
	else if (line[index] == 'W' && line[++index] == 'E')
		parser_index_two(line, 4, ++index, cub);
	else if (line[index] == 'E' && line[++index] == 'A')
		parser_index_two(line, 5, ++index, cub);
	else if (line[--index] == 'S' && !ft_isalpha(line[++index]))
		parser_index_two(line, 6, index, cub);
}

void				parsing(char **argv, t_cub *cub)
{
	int		fd;
	int		coll_line;
	char	*line;

	coll_line = 0;
	if ((fd = open(argv[1], O_RDONLY)) && fd == -1)
		error("Error\nFile not found or not open", cub);
	while (get_next_line(fd, &line) && coll_line++ != 8)
	{
		if (ft_strlen(line) == 0)
			coll_line--;
		else
		{
			check_space_tab(line, cub);
			parser_index(line, cub);
			if (coll_line == 8)
			{
				check_all(cub);
				break ;
			}
		}
		free(line);
	}
	free(line);
	map_parsing(fd, cub);
}