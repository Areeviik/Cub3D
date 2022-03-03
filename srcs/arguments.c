/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:05:28 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/19 15:05:38 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_arg_name(char *argv)
{
	if (argv[ft_strlen(argv) - 1] == 'b' && argv[ft_strlen(argv) - 2] == 'u'
		&& argv[ft_strlen(argv) - 3] == 'c' && argv[ft_strlen(argv) - 4] == '.')
		return (0);
	else
		return (1);
}

int		check_save(char *argv)
{
	if (argv[0] == '-' && argv[1] == '-'
		&& argv[2] == 's' && argv[3] == 'a'
		&& argv[4] == 'v' && argv[5] == 'e')
		return (0);
	else
		return (1);
}

void	check_args(int argc, char **argv, t_cub *cub)
{
	if (argc != 2 && argc != 3)
		error("Error\nNot true arguments", cub);
	else if (argc == 2)
	{
		if (check_arg_name(argv[1]))
			error("Error\nThe end of map name is not'.cub'", cub);
	}
	else if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6 || check_save(argv[2]))
			error("Error\n3rd argument is not --save", cub);
	}
}

void	check_space_tab(char *line, t_cub *cub)
{
	if (line[ft_strlen(line) - 1] == ' ')
		error("Error\nSpace after indexer", cub);
}
