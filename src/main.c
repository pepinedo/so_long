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

int	main(int argc, char **argv)
{
	t_data data;

	if (argc <= 1)
		exit_with_message(data, "Error\nTo few arguments\n\n", 0);
	if (argc > 2)
		exit_with_message(data, "Error\nTo much arguments\n", 0);
	map_parsec(argv[1], &data);
	the_game(&data);
	exit_with_message_improved(data, "Execution finished.\n", 2)
	return (0);
}