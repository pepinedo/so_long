/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:19:13 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/06 16:36:50 by ppinedo-         ###   ########.fr       */
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

# define WIDTH 64
# define HEIGHT 64

typedef struct s_data
{
	int		height;
	int		width;
	int*	line_width;
	char**	mapstr;
}				t_data;

int		main(int argc, char **argv);

//----------Map Parsec Functions---------
int		map_parsec(char *fdmap, t_data *data);
void	check_if_its_ber(char *fdmap);
void	map_height(char *fdmap, t_data *data);
void	map_char(char *fdmap, t_data *data);
void	map_width(char *fdmap, t_data *data);

//----------Checker functions-------------
void	check_if_its_ber(char *fdmap);
void	check_if_its_rectangular(t_data *data);

//----------Utils------------------------
void	ft_strdup_without_n(const char *str, int i, t_data *data);

void	exit_with_message(int a);

#endif