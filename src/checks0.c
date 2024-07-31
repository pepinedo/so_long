/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:39:12 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/07/31 13:07:17 by ppinedo-         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < (data->height - 2))
	{
		if (data->line_width[i] != data->line_width[i + 1])
			exit_with_message(data, "Error\nThe map is not rectangular\n", 1);
		i++;
	}
	if (data->line_width[i] != (data->line_width[i + 1] + 1))
	{
		if (data->mapstr[i + 1][0] != '\n')
			exit_with_message(data, "Error\nThe map is not rectangular\n", 1);
	}
}

void	check_if_have_exit(t_data *data)
{
	int	x;
	int	y;
	int	e;

	y = 0;
	x = 0;
	e = 0;
	while (x < data->height)
	{
		y = 0;
		while (data->mapstr[x][y])
		{
			if (data->mapstr[x][y] == 'E')
			{
				e++;
				data->exit_y = y + 1;
				data->exit_x = x + 1;
			}
			y++;
		}
		x++;
	}
	check_if_have_exit_message(data, e);
}

void	check_collectibles(t_data *data)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	i = 0;
	c = 0;
	while (i < data->height)
	{
		while (data->mapstr[i][j])
		{
			if (data->mapstr[i][j] == 'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	if (c == 0)
		exit_with_message(data, "Error\nMap without collectibles\n", 1);
	data->collectibles = c;
}
