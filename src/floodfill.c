/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:44:44 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/04 17:32:19 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(char **map)
{
	int i;

	i = 0;
	while (i < 6)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	copy_map(t_data *data)
{
	int		i;

	data->mapstrcopy = (char **)malloc(sizeof(char *) * data->height);
	if (data->mapstrcopy == NULL)
		return ;
	i = 0;
	while (i < data->height)
	{
		data->mapstrcopy[i] = (char *)malloc(sizeof(char) * (data->height));
		if (data->mapstrcopy[i] == NULL)
			return ;
		data->mapstrcopy[i] = ft_strtrim(data->mapstr[i], "\n");
		i++;
	}
}

void    check_flood(char **map)
{
    int x;
	int y;

	x = 0;
	y = 0;
	while (map[x][y])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P' || map[x][y] == 'C' || map[x][y] == 'E')
			{
				exit_with_message(12);
			}
			y++;
		}
		x++;
	}
	printf("Salida alcanzable con todos los coleccionables.\n");
}

void	floodfill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[x][y] || map[x][y] == '1')
		return;
	print_map(map);
	if (map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'E' || map[x][y] == 'P')
	{
		map[x][y] = '1';
		floodfill(map, x + 1, y);
		floodfill(map, x, y + 1);
		floodfill(map, x - 1, y);
		floodfill(map, x, y - 1);
	}
}
