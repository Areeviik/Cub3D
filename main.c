/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:20:52 by akhachat          #+#    #+#             */
/*   Updated: 2021/05/17 17:55:06 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_cub cub;

	check_args(argc, argv, &cub);
	parsing(argv, &cub);
	begin(&cub, argc);
	return (0);
}
