/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:19:13 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/05 16:53:19 by ppinedo-         ###   ########.fr       */
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

# define WIDTH 64
# define HEIGHT 64

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_images;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_textures;

typedef struct s_data
{
	char**		mapstr;
	char**		mapstrcopy;
	int			height;
	int			width;
	int*		line_width;
	int			player_y;
	int			player_x;
	int 		collectibles;
	int			exit_x;
	int			exit_y;
	mlx_t		*mlx;
	t_textures 	*textures;
	t_images	*images;

}				t_data;

int		main(int argc, char **argv);

//----------Map Parsec Functions---------
void		map_parsec(char *fdmap, t_data *data);
void	check_if_its_ber(char *fdmap);
void	map_height(char *fdmap, t_data *data);
void	map_char(char *fdmap, t_data *data);
void	map_width(char *fdmap, t_data *data);
void	floodfill(char **map, int x, int y);
void    check_flood(t_data *data);

//----------Check functions-------------
void	check_if_its_ber(char *fdmap);
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

void	exit_with_message(int a);
void	ft_free1(t_data *data);
void	ft_freestr(char **s);
void	ft_free2(t_data *data);

#endif