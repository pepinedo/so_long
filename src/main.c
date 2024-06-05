/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:05 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/05 16:17:20 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	inizialice_variables(t_data *data)
// {
// 	data->count_exit = 0;
// 	data->count_collect = 0;
// 	data->count_player = 0;
// 	data->player_x = 0;
// 	data->player_y = 0;
// 	data->exit_x = 0;
// 	data->exit_y = 0;
// 	data->line = 0;
// 	data->col = 0;
// }

int	main(int argc, char **argv)
{
	t_data data;

	if (argc <= 1)
		exit_with_message(1);
	if (argc > 2)
		exit_with_message(2);
	map_parsec(argv[1], &data);

	
	// mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	// if (!mlx)
	// 	ft_error();
	ft_free2(&data);
	return (0);
}