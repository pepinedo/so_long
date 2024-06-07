/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:19:13 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/07 13:43:36 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define P_WIDTH 64
# define P_HEIGHT 64

typedef struct s_data
{
	char**			mapstr;
	char**			mapstrcopy;
	int				height;
	int				width;
	int*			line_width;
	int				player_x;
	int				player_y;
	int 			collectibles;
	int				exit_x;
	int				exit_y;
	mlx_texture_t*	texture_wall;
	mlx_texture_t*	texture_floor;
	mlx_texture_t*	texture_player;
	mlx_texture_t*	texture_collectible;
	mlx_texture_t*	texture_exit;
	mlx_image_t*	image_wall;
	mlx_image_t*	image_floor;
	mlx_image_t*	image_player;
	mlx_image_t*	image_collectible;
	mlx_image_t*	image_exit;
	mlx_t*			mlx;
	mlx_image_t*	count_move;
	int				total_moves;
	int				fail_exit;
	int				catched_collectible;

}				t_data;

//-------------MAIN----------------------
int		main(int argc, char **argv);

//----------Map Parsec Functions---------
void	map_parsec(char *fdmap, t_data *data);
void	map_height(char *fdmap, t_data *data);
void	map_char(char *fdmap, t_data *data);
void	map_width(char *fdmap, t_data *data);
void	floodfill(char **map, int x, int y);
void    check_flood(t_data *data);

//----------Check functions-------------
void	check_if_its_ber(t_data *data, char *fdmap);
void	check_if_its_rectangular(t_data *data);
void	check_if_its_enclosed(t_data *data);
void	line_are_all_1(char *line, t_data *data);
void	column_are_all_1(t_data *data, int column);
void	check_if_have_exit(t_data *data);
void	check_collectibles(t_data *data);
void	check_starting_position(t_data *data);
void	check_characters(t_data *data);

//----------Utils------------------------
void	ft_strdup_without_n(const char *str, int i, t_data *data);
void	print_map(char **map);
void	copy_map(t_data *data);
void	exit_with_message(t_data *data, char *str, int i);
void	exit_before_inicializate(char *str);
void	ft_freestr(char **s);
void    detele_textures(t_data *data);

//--------------Game----------------------
void    the_game(t_data *data);
bool    load_pngs(t_data *data);
bool	png_to_image(t_data *data);
void    images_to_window(t_data *data);
void	draw_the_sqm(int x, int y, char c, t_data *data);
void	set_keys(mlx_key_data_t keycode, void *param);
void    player_movement(t_data *data, int tx, int ty);
void	move_to_floor(t_data *data, int x, int y);
void	move_to_collectible(t_data *data, int x, int y);
void	move_to_exit(t_data *data, int x, int y);
void    delete_textures(t_data *data);
void	set_variables(t_data *data);

#endif