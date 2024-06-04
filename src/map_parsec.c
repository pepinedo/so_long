/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:00:07 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/04 17:47:47 by ppinedo-         ###   ########.fr       */
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
	data->mapstr = (char **)malloc(sizeof(char *) * data->height);
	if (data->mapstr == NULL)
		return ;
	i = 0;
	while (i < data->height)
	{
		str = get_next_line(fd);
		data->mapstr[i] = (char *)malloc(sizeof(char) * (data->height));
		if (data->mapstr[i] == NULL)
			return ;
		data->mapstr[i] = ft_strtrim(str, "\n");
		printf("%s\n", data->mapstr[i]);
		i++;
	}
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
		printf("el ancho es -> %i\n", data->line_width[i]);
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
		return ;
	line = get_next_line(fd);
	data->height = 0;
	while (line)
	{
		(data->height)++;
		line = get_next_line(fd);
	}
	printf("el alto es -> %i\n", data->height);
	close(fd);
}

int	map_parsec(char *fdmap, t_data *data)
{
	check_if_its_ber(fdmap);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	map_height(fdmap, data);
	map_width(fdmap, data);
	map_char(fdmap, data);
	check_if_its_ber(fdmap);
	check_if_its_rectangular(data);
	check_characters(data);
	check_if_its_enclosed(data);
	check_if_have_exit(data);
	check_collectibles(data);
	check_starting_position(data);
	check_characters(data);
	copy_map(data);
	floodfill(data->mapstrcopy, data->start_x, data->start_y);
	check_flood(data->mapstrcopy);
	printf("Parseo completado y todo bien\n");
	return (0);
}