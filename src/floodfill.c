/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:44:44 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/22 10:49:11 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floodfill(char **map, int y, int x, int collectibles) //contadores y salida
{
	bool	exit;

	exit = false;
	if (map[y + 1][x] != '1')
	{
		if (map[y + 1][x] == 'C')
			collectibles--;
		if (map[y + 1][x] == 'E')
			exit = true;
		map[y + 1][x] = '1';
		floodfill(map, ++y, x, collectibles);
	}
	if (map[y][x + 1] != '1')
	{
		if (map[y + 1][x] == 'C')
			collectibles--;
		if (map[y + 1][x] == 'E')
			exit = true;
		map[y + 1][x] = '1';
		floodfill(map, y, ++x, collectibles);
	}
	if (map[y - 1][x] != '1')
	{
		if (map[y + 1][x] == 'C')
			collectibles--;
		if (map[y + 1][x] == 'E')
			exit = true;
		map[y + 1][x] = '1';
		floodfill(map, --y, x, collectibles);
	}
	if (map[y][x - 1] != '1')
	{
		if (map[y + 1][x] == 'C')
			collectibles--;
		if (map[y + 1][x] == 'E')
			exit = true;
		map[y + 1][x] = '1';
		floodfill(map, y, --x, collectibles);
	}
	if (collectibles != 0 && !exit)
		exit_with_message(11);
}
