/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:05 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/04 17:33:38 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc <= 1)
		exit_with_message(1);
	if (argc > 2)
		exit_with_message(2);
	map_parsec(argv[1], &data);
	
	return (0);
}