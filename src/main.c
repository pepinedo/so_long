/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:05 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/29 11:47:12 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	void	*data;
	void	*mlx_ptr;

	data = NULL;
	mlx_ptr = mlx_init(512, 512, "VIDEOJUEGO", true);
	if (!mlx_ptr)
		return (1);
	mlx_loop(data);
	free(data);
	return (0);
}