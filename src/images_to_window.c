/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_to_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:25:44 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 01:25:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Poner bien el header!!!!!!!!

#include "../includes/so_long.h"

void	draw_the_sqm(int x, int y, char c, t_data *data)
{
	mlx_image_to_window(data->mlx, data->images.floor, P_WIDTH * x, P_HEIGHT * y);
	if (c == '1')
		mlx_image_to_window(data->mlx, data->images.wall,  P_WIDTH * x, P_HEIGHT * y);
	if (c == 'P')
		mlx_image_to_window(data->mlx, data->images.player, P_WIDTH * x, P_HEIGHT * y);
	if (c == 'C')
		mlx_image_to_window(data->mlx, data->images.collectible, P_WIDTH * x, P_HEIGHT * y);
	if (c == 'E')
		mlx_image_to_window(data->mlx, data->images.exit, P_WIDTH * x, P_HEIGHT * y);
}

void    images_to_window(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->mapstr[x])
	{
		y = 0;
		while (data->mapstr[x][y])
		{
			draw_the_sqm(x, y, data->mapstr[x][y], data);
			y++;
		}
		x++;
	}
}

bool    load_pngs(t_data *data) //aqui hay que crear la carpeta de las imagenes, descargar las imagenes ahí y poner la ruta en cada funcion
{
    data->textures.wall = mlx_load_png(./textures/wall.png);
    if (!data->wall_png)
        return (false);
    data->textures.floor = mlx_load_png(./textures/floor.png);
    if (!data->wall_png)
        return (false);
    data->textures.player = mlx_load_png(./textures/player.png);
    if (!data->wall_png)
        return (false);
    data->textures.collectible = mlx_load_png(./textures/collectible.png);
    if (!data->wall_png)
        return (false);
    data->textures.exit = mlx_load_png(./textures/exit.png);
    if (!data->wall_png)
        return (false);
    return (true);
}
