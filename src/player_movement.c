/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:41:59 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 09:15:21 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Poner bien el header!!!!!!!!

#include "../includes/so_long.h"

void	move_to_exit(t_data *data, int x, int y)
{
	int	px;
	int	py;

	px = data->player_x;
	py = data->player_y;
	data->mapstr[py][px] = '0';
	data->mapstr[py + y][px + x] = 'P';
	data->player_x = data->player_x + x;
	data->player_y = data->player_y + y;
	draw_the_sqm(px, py, 'E', data);
    draw_the_sqm(data->player_x, data->player_y, 'P', data);
}

void	move_to_collectible(t_data *data, int x, int y)
{
	int	px;
	int	py;

	px = data->player_x;
	py = data->player_y;
	data->mapstr[py][px] = '0';
	data->mapstr[py + y][px + x] = 'P';
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
	data->mapstr[py][px] = '0';
	data->mapstr[py + y][px + x] = 'P';
	data->player_x = data->player_x + x;
	data->player_y = data->player_y + y;
    draw_the_sqm(px, py, '0', data);
	draw_the_sqm(data->player_x, data->player_y, 'P', data);
}

/*
void    print_moves(t_data *data)
{
    data->total_moves++;
    temp = ft_itoa(data->total_moves);
	if (data->count_move)
		mlx_delete_image(data->mlx, data->count_move);
	data->count_move = mlx_put_string(data->mlx, temp, 0, 0);
	free(temp);
}
*/

void    player_movement(t_data *data, int tx, int ty)
{
    int	px;
	int	py;

	px = data->player_x;
	py = data->player_y;
	if (data->mapstr[px + tx][py + ty] == '1') //if es una pared 
		return ;
	if (data->mapstr[px + tx][py + ty] == '0')
		move_to_floor(data, tx, ty);
	if (data->mapstr[px + tx][py + ty] == 'C')
		move_to_collectible(data, tx, ty);
	if (data->mapstr[px + tx][py + ty] == 'E' && data->collectibles != 0)
		move_to_exit(data, tx, ty);
	if (data->mapstr[px + tx][py + ty] == 'E' && data->collectibles == 0)
	{
		ft_printf("YOU WIN IN %d MOVES\n", data->total_moves);
		mlx_close_window(data->mlx);
		return ;
	}
//	print_moves(data); ???
    data->total_moves++;
	ft_printf("Moves count: < %d >\n", data->total_moves);
}