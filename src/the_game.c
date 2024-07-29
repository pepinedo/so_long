/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:21 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/07 13:36:22 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_textures(t_data *data)
{
	mlx_delete_texture(data->texture_wall);
	mlx_delete_texture(data->texture_floor);
	mlx_delete_texture(data->texture_player);
	mlx_delete_texture(data->texture_collectible);
	mlx_delete_texture(data->texture_exit);
}

void	print_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			ft_printf("%c", map[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}

void	set_keys(mlx_key_data_t keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keycode.key == MLX_KEY_A && keycode.action == MLX_PRESS)
		player_movement(data, 0, -1);
	if (keycode.key == MLX_KEY_D && keycode.action == MLX_PRESS)
		player_movement(data, 0, +1);
	if (keycode.key == MLX_KEY_W && keycode.action == MLX_PRESS)
		player_movement(data, -1, 0);
	if (keycode.key == MLX_KEY_S && keycode.action == MLX_PRESS)
		player_movement(data, +1, 0);
	if (keycode.key == MLX_KEY_Q && keycode.action == MLX_PRESS)
		print_map(data->mapstr);
}

void	the_game(t_data *data)
{
	data->mlx = mlx_init(P_WIDTH * data->width, P_HEIGHT * data->height, " < EL JUEGO > ", false);
	if (!data->mlx)
		exit_with_message(data, "Error\nMLX load failure.\n", 2);
	if (!load_pngs(data))
		exit_with_message(data, "Error\nImages not found.\n", 2);
	images_to_window(data);
	mlx_key_hook(data->mlx, &set_keys, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	delete_textures(data);
}
