/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:33:10 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 00:33:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Poner bien el header!!!!!!!!

#include "../includes/so_long.h"

bool    load_images(t_data *data)
{
    data->textures. = mlx_load_png(ruta de la imagen);
    if (!data->wall_png)
        return (false);

}

void    the_game(t_data *data)
{
    data->mlx = mlx_init(WIDTH * data->width, HEIGHT * data->height, "--.-.-.-.--", false);
    if (!data->mlx)
        exit_with_message_improved(data, "Error\nFailed MLX load.\n", 2); //modificar los exits en el parseo
    if (!load_image(data))
        exit_with_message_improved(data, "Error\nImages not found.\n", 2);
}