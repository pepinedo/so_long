/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:05 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/06 15:37:40 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checkear que sea .ber, leerlo,
//	pasarlo a char** el contenido,y ya despues las comprobaciones

int	main(int argc, char **argv)
{
	t_data data;

	if (argc <= 1)
		exit_with_message(1);
	if (argc > 2)
		exit_with_message(2);
	map_parsec(argv[1], &data);
	// mlx_ptr = mlx_init(512, 512, "VIDEOJUEGO", true);
	// // funcion de recibir teclas (mlx_hook)(key_hook)
	// mlx_loop(mlx_ptr);
	// free(mlx_ptr);
	return (0);
}