/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_to_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:03:35 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/07 13:03:37 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_the_sqm(int x, int y, char c, t_data *data)
{
	mlx_image_to_window(data->mlx, data->image_floor, P_WIDTH * y, P_HEIGHT * x);
	if (c == '1')
		mlx_image_to_window(data->mlx, data->image_wall,  P_WIDTH * y, P_HEIGHT * x);
	if (c == 'P')
		mlx_image_to_window(data->mlx, data->image_player, P_WIDTH * y, P_HEIGHT * x);
	if (c == 'C')
		mlx_image_to_window(data->mlx, data->image_collectible, P_WIDTH * y, P_HEIGHT * x);
	if (c == 'E')
		mlx_image_to_window(data->mlx, data->image_exit, P_WIDTH * y, P_HEIGHT * x);
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

bool	png_to_image(t_data *data)
{
	data->image_floor = mlx_texture_to_image(data->mlx, data->texture_floor);
	if (!data->image_floor)
        return (false);
	data->image_wall = mlx_texture_to_image(data->mlx, data->texture_wall);
	if (!data->image_wall)
        return (false);
	data->image_player = mlx_texture_to_image(data->mlx, data->texture_player);
	if (!data->image_player)
        return (false);
	data->image_collectible = mlx_texture_to_image(data->mlx, data->texture_collectible);
	if (!data->image_collectible)
        return (false);
	data->image_exit = mlx_texture_to_image(data->mlx, data->texture_exit);
	if (!data->image_exit)
        return (false);
	return (true);
}

bool    load_pngs(t_data *data)
{
    data->texture_wall = mlx_load_png("./textures/wall.png");
    if (!data->texture_wall)
        return (false);
    data->texture_floor = mlx_load_png("./textures/floor.png");
    if (!data->texture_floor)
        return (false);
    data->texture_player = mlx_load_png("./textures/player.png");
    if (!data->texture_player)
        return (false);
    data->texture_collectible = mlx_load_png("./textures/collectible.png");
    if (!data->texture_collectible)
        return (false);
    data->texture_exit = mlx_load_png("./textures/exit.png");
    if (!data->texture_exit)
	{
        return (false);
	}
	if (!png_to_image(data))
		return (false);
    return (true);
}
