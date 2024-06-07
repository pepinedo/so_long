/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:39:12 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/07 12:55:03 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_if_its_ber(t_data *data, char *fdmap)
{
	int	i;

	i = 0;
	while (fdmap[i])
		i++;
	if (fdmap[--i] != 'r' || fdmap[--i] != 'e' || fdmap[--i] != 'b'
		|| fdmap[--i] != '.')
		exit_with_message(data, "Error\nArgument is not a .ber file\n", 0);
}

void	check_if_its_rectangular(t_data *data)
{
	int i;

	i = 0;
	while(i < (data->height - 2))
	{
		if (data->line_width[i] != data->line_width[i + 1])
			exit_with_message(data, "Error\nThe map is not rectangular\n", 1);
		i++;
	}
	if(data->line_width[i] != (data->line_width[i + 1] + 1))
	{
		if (data->mapstr[i + 1][0] != '\n')
			exit_with_message(data, "Error\nThe map is not rectangular\n", 1);
	}
}

void	check_if_have_exit(t_data *data)
{
	int x;
	int y;
	int E;

	y = 0;
	x = 0;
	E = 0;
	while(x < data->height)
	{
		y = 0;
		while(data->mapstr[x][y])
		{
			if (data->mapstr[x][y] == 'E')
			{
				E++;
				data->exit_y = y + 1;
				data->exit_x = x + 1;
			}
			y++;
		}
		x++;
	}
	if (E == 0)
		exit_with_message(data, "Error\nMap without exit\n", 1);
	if (E > 1)
		exit_with_message(data, "Error\nMap with more than 1 exit\n", 1);
}

void	check_collectibles(t_data *data)
{
	int i;
	int j;
	int C;

	j = 0;
	i = 0;
	C = 0;
	while(i < data->height)
	{
		while(data->mapstr[i][j])
		{
			if (data->mapstr[i][j] == 'C')
				C++;
			j++;
		}
		i++;
		j = 0;
	}
	if (C == 0)
		exit_with_message(data, "Error\nMap without collectibles\n", 1);
	data->collectibles = C;
}

void	check_starting_position(t_data *data)
{
	int x;
	int y;
	int P;

	y = 0;
	x = 0;
	P = 0;
	while(x < data->height)
	{
		y = 0;
		while(data->mapstr[x][y])
		{
			if (data->mapstr[x][y] == 'P')
			{
				P++;
				data->player_y = y + 1;
				data->player_x = x + 1;
			}
			y++;
		}
		x++;
	}
	if (P == 0)
		exit_with_message(data, "Error\nMap without starting position\n", 1);
	if (P > 1)
		exit_with_message(data, "Error\nMap with more than 1 starting position\n", 1);
}

void	column_are_all_1(t_data *data, int column)
{
	int i;
	
	i = 0;
	while(i < data->height)
	{
		if (data->mapstr[i][column] != '1')
			exit_with_message(data, "Error\nThe map is not enclosed\n", 1);
		i++;
	}
}

void	line_are_all_1(char *line, t_data *data)
{
	int i;

	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
	{
		if(line[i] != '1')
			exit_with_message(data, "Error\nThe map is not enclosed\n", 1);
		i++;
	}
}

void	check_if_its_enclosed(t_data *data)
{
	line_are_all_1(data->mapstr[0], data);
	line_are_all_1(data->mapstr[data->height - 1], data);
	column_are_all_1(data, 0);
	column_are_all_1(data, data->width - 1);
	
}

void	check_characters(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->mapstr[x] && data->mapstr[x][y] != '\0' && data->mapstr[x][y] != '\n')
	{
		while (data->mapstr[x][y] != '\0' && data->mapstr[x][y] != '\n')
		{
			if (data->mapstr[x][y] != '1' && data->mapstr[x][y] != '0' && data->mapstr[x][y] != 'P' && data->mapstr[x][y] != 'C' && data->mapstr[x][y] != 'E')
				exit_with_message(data, "Error\nMap with invalid characters\n", 1);
			y++;
		}
		x++;
		y = 0;
	}
}