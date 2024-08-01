/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:00:07 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/08/01 14:06:03 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_char(char *fdmap, t_data *data)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(fdmap, O_RDONLY);
	if (fd == -1)
		return ;
	data->mapstr = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->mapstr == NULL)
		return ;
	i = 0;
	while (i < data->height)
	{
		str = get_next_line(fd);
		data->mapstr[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	data->mapstr[i] = NULL;
	close(fd);
}

void	map_width(char *fdmap, t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(fdmap, O_RDONLY);
	if (fd == -1)
		return ;
	data->line_width = (int *)malloc(sizeof(int) * data->height);
	if (data->line_width == NULL)
		return ;
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		data->line_width[i] = (int)ft_strlen(line);
		free(line);
		i++;
	}
	data->width = (data->line_width[0] - 1);
	close(fd);
}

void	map_height(char *fdmap, t_data *data)
{
	char	*line;
	int		fd;

	fd = open(fdmap, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Invalid file.\n");
		exit(1);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Empty map.\n");
		exit(1);
	}
	data->height = 0;
	while (line)
	{
		free(line);
		(data->height)++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	map_parsec(char *fdmap, t_data *data)
{
	check_if_its_ber(data, fdmap);
	map_height(fdmap, data);
	map_width(fdmap, data);
	map_char(fdmap, data);
	check_characters(data);
	check_if_its_rectangular(data);
	check_if_its_enclosed(data);
	check_starting_position(data);
	check_if_have_exit(data);
	check_collectibles(data);
	copy_map(data);
	floodfill(data->mapstrcopy, data->player_x - 1, data->player_y - 1);
	check_flood(data);
	data->total_moves = 0;
	printf("✅​ MAPA OK.\n");
	return ;
}
