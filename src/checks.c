/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:39:12 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/22 10:51:37 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_if_its_ber(char *fdmap)
{
	int	i;

	i = 0;
	while (fdmap[i])
		i++;
	if (fdmap[--i] != 'r' && fdmap[--i] != 'e' && fdmap[--i] != 'b'
		&& fdmap[--i] != '.')
		exit_with_message(3);
}

void	check_if_its_rectangular(t_data *data)
{
	int i;

	i = 0;
	while(i < (data->height - 2))
	{
		if (data->line_width[i] != data->line_width[i + 1])
			exit_with_message(4);
		i++;
	}
	if(data->line_width[i] != (data->line_width[i + 1] + 1))
		exit_with_message(4);
}

void	line_are_all_1(char *line)
{
	int i;

	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
	{
		if(line[i] != '1')
			exit_with_message(5);
		i++;
	}
}

void	column_are_all_1(t_data *data, int column)
{
	int i;
	
	i = 0;
	while(i < data->height)
	{
		if (data->mapstr[i][column] != '1')
			exit_with_message(5);
		i++;
	}
}

void	check_if_have_exit(t_data *data)
{
	int i;
	int j;
	int E;

	j = 0;
	i = 0;
	E = 0;
	while(i < data->height)
	{
		while(data->mapstr[i][j])
		{
			if (data->mapstr[i][j] == 'E')
				E++;
			j++;
		}
		i++;
		j = 0;
	}
	if (E == 0)
		exit_with_message(6);
	if (E > 1)
		exit_with_message(7);
	printf("El mapa tiene 1 salida\n");
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
		exit_with_message(8);
	data->collectibles = C;
	printf("El mapa tiene %i coleccionables\n", data->collectibles);
}

void	check_starting_position(t_data *data)
{
	int y;
	int x;
	int P;

	y = 0;
	x = 0;
	P = 0;
	while(y < data->height)
	{
		while(data->mapstr[y][x])
		{
			if (data->mapstr[y][x] == 'P')
				P++;
			x++;
		}
		y++;
		x = 0;
	}
	data->start_y = y;
	data->start_x = x;
	if (P == 0)
		exit_with_message(9);
	if (P > 1)
		exit_with_message(10);
	printf("El mapa tiene una posicion de salida\n");
}

void	check_if_its_enclosed(t_data *data)
{
	line_are_all_1(data->mapstr[0]);
	line_are_all_1(data->mapstr[data->height - 1]);
	column_are_all_1(data, 0);
	column_are_all_1(data, data->width - 1);
	printf("El mapa está cerrado\n");
}