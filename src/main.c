/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:05 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/29 14:00:19 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checkear que sea .ber, leerlo, pasarlo a char** el contenido,y ya despues las comprobaciones
	
int	map_parsec(char *fdmap)
{
	int 	i;
	char 	**map;
	char	line;

	open(map, O_RDONLY);
	i = -1;
	map = malloc(height * size(char));
	while (++i < height)
	{
		line = get_next_line(fdmap);
		map[i] = malloc(strlen(line) + 1 * sizeof(char));
		map[i] = strdup(line);
	}
	i = -1;
	while (++i < height)
		printf("%s", map[i]);
}

int main(int ac, char **argv)
{
	void *mlx_ptr;

	map_parsec(argv[1]);
	mlx_ptr = mlx_init(512, 512, "VIDEOJUEGO", true);
	// funcion de recibir teclas (mlx_hook)(key_hook)
	mlx_loop(mlx_ptr);
	free(mlx_ptr);
	return (0);
}