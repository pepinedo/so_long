/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:33:10 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 09:16:28 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Poner bien el header!!!!!!!!

#include "../includes/so_long.h"

void    delete_textures(t_data *data)
{
    mlx_delete_texture(data->textures->wall);
	mlx_delete_texture(data->textures->floor);
	mlx_delete_texture(data->textures->player);
	mlx_delete_texture(data->textures->collectible);
	mlx_delete_texture(data->textures->exit);
}

void	set_keys(mlx_key_data_t keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keycode.key == MLX_KEY_A && keycode.action == MLX_PRESS)
		player_movement(data, -1, 0);
	if (keycode.key == MLX_KEY_D && keycode.action == MLX_PRESS)
		player_movement(data, +1, 0);
	if (keycode.key == MLX_KEY_W && keycode.action == MLX_PRESS)
		player_movement(data, 0, -1);
	if (keycode.key == MLX_KEY_S && keycode.action == MLX_PRESS)
		player_movement(data, 0, +1);
}

void    the_game(t_data *data)
{
    data->mlx = mlx_init(P_WIDTH * data->width, P_HEIGHT * data->height, " < so_long, EL JUEGO > ", false);
    if (!data->mlx)
        exit_with_message(data, "Error\nMLX load failure.\n", 2);
    if (!load_pngs(data))
        exit_with_message(data, "Error\nImages not found.\n", 2);
    images_to_window(data);
    mlx_key_hook(data->mlx, &set_keys, data);
    mlx_loop(data->mlx);
    mlx_delete_texture(data->t.wall);
    detele_textures(data);
	mlx_terminate(data->mlx);
	return (0);
}