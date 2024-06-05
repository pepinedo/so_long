/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:44:44 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/05 17:05:30 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	print_map(char **map)
// {
// 	int i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }

void	copy_map(t_data *data)
{
	int		i;

	data->mapstrcopy = (char **)malloc(sizeof(char *) * data->height);
	if (data->mapstrcopy == NULL)
		return ;
	i = 0;
	while (i < data->height)
	{
		data->mapstrcopy[i] = ft_strtrim(data->mapstr[i], "\n");
		i++;
	}
}

void    check_flood(t_data *data)
{
    int x;
	int y;

	x = 0;
	y = 0;
	while (x < data->height)
	{
		while (data->mapstrcopy[x][y] != '\0' && data->mapstrcopy[x][y] != '\n')
		{
			if (data->mapstrcopy[x][y] == 'P' || data->mapstrcopy[x][y] == 'C' || data->mapstrcopy[x][y] == 'E')
			{
				exit_with_message(12);
				ft_free2(data);
			}
			y++;
		}
		x++;
		y = 0;
	}
}

void	floodfill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || map[x][y] == '\0' || map[x][y] == '1' || map[x][y] == '*')
		return;
	if (map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'E' || map[x][y] == 'P')
	{
		map[x][y] = '*';
		floodfill(map, x + 1, y);
		floodfill(map, x, y + 1);
		floodfill(map, x - 1, y);
		floodfill(map, x, y - 1);
	}
}
