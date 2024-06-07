/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:05 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/07 12:58:00 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_variables(t_data *data)
{
	data->total_moves = 0;
	data->player_x--;
	data->player_y--;
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc <= 1)
		exit_before_inicializate("Error\nTo few arguments\n\n");
	if (argc > 2)
		exit_before_inicializate("Error\nTo much arguments\n");
	map_parsec(argv[1], &data);
	set_variables(&data);
	the_game(&data);
	exit_with_message(&data, "Execution finished.\n", 3);
	return (0);
}