/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:56:59 by linuxpedro        #+#    #+#             */
/*   Updated: 2024/07/31 12:58:19 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_starting_position(t_data *data)
{
	int	x;
	int	y;
	int	p;

	y = 0;
	x = 0;
	p = 0;
	while (x < data->height)
	{
		y = 0;
		while (data->mapstr[x][y])
		{
			if (data->mapstr[x][y] == 'P')
			{
				p++;
				data->player_y = y + 1;
				data->player_x = x + 1;
			}
			y++;
		}
		x++;
	}
}

void	column_are_all_1(t_data *data, int column)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->mapstr[i][column] != '1')
			exit_with_message(data, "Error\nThe map is not enclosed\n", 1);
		i++;
	}
}

void	line_are_all_1(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
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
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->mapstr[x] && data->mapstr[x][y]
			!= '\0' && data->mapstr[x][y] != '\n')
	{
		while (data->mapstr[x][y] != '\0' && data->mapstr[x][y] != '\n')
		{
			if (data->mapstr[x][y] != '1' && data->mapstr[x][y] != '0' &&
					data->mapstr[x][y] != 'P' && data->mapstr[x][y] !=
							'C' && data->mapstr[x][y] != 'E')
				exit_with_message(data, "Error\nInvalid character map\n", 1);
			y++;
		}
		x++;
		y = 0;
	}
}
