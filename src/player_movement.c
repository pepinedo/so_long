/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:58 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/07 13:46:35 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_to_exit(t_data *data, int x, int y)
{
	int	px;
	int	py;

	px = data->player_x;
	py = data->player_y;
	data->mapstr[px][py] = '0';
	data->mapstr[px + x][py + y] = 'P';
	data->player_x = data->player_x + x;
	data->player_y = data->player_y + y;
	draw_the_sqm(px, py, '0', data);
    draw_the_sqm(data->player_x, data->player_y, 'P', data);
	data->fail_exit = 1;
}

void	move_to_collectible(t_data *data, int x, int y)
{
	int	px;
	int	py;

	px = data->player_x;
	py = data->player_y;
	data->mapstr[px][py] = '0';
	data->mapstr[px + x][py + y] = 'P';
	data->player_x = data->player_x + x;
	data->player_y = data->player_y + y;
    draw_the_sqm(px, py, '0', data);
	draw_the_sqm(data->player_x, data->player_y, 'P', data);
	data->collectibles--;
}

void	move_to_floor(t_data *data, int x, int y)
{
	int	px;
	int	py;

	px = data->player_x;
	py = data->player_y;
	data->mapstr[px][py] = '0';
	data->mapstr[px + x][py + y] = 'P';
	data->player_x = data->player_x + x;
	data->player_y = data->player_y + y;
    draw_the_sqm(px, py, '0', data);
	if (data->fail_exit == 1)
	{
		data->mapstr[px][py] = 'E';
		data->fail_exit = 0;
		draw_the_sqm(px, py, 'E', data);
	}
	draw_the_sqm(data->player_x, data->player_y, 'P', data);
}

void    player_movement(t_data *data, int tx, int ty)
{
    int	px;
	int	py;

	px = data->player_x;
	py = data->player_y;
	if (data->mapstr[px + tx][py + ty] == '1')
		return ;
	if (data->mapstr[px + tx][py + ty] == '0')
		move_to_floor(data, tx, ty);
	if (data->mapstr[px + tx][py + ty] == 'C')
		move_to_collectible(data, tx, ty);
	if (data->mapstr[px + tx][py + ty] == 'E' && data->collectibles != 0)
		move_to_exit(data, tx, ty);
	if (data->mapstr[px + tx][py + ty] == 'E' && data->collectibles == 0)
	{
		ft_printf("​🎉​🎉​ YOU WIN IN %d MOVES! ​🎉​🎉​\n", data->total_moves);
		mlx_close_window(data->mlx);
		return ;
	}
    data->total_moves++;
	ft_printf("Move count:         < 🚶%d >\nCollectibles count: < 🏆​%d >\n", data->total_moves, data->collectibles);
}