/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:32 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/06/05 16:16:42 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_freestr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free2(t_data *data)
{
	ft_freestr(data->mapstr);
	ft_freestr(data->mapstrcopy);
	free(data->line_width);
	free(data);
	exit (0);
}

void	ft_free1(t_data *data)
{
	ft_freestr(data->mapstr);
	free(data->line_width);
	free(data);
	exit (0);
}

void	exit_with_message(int a)
{
	if (a == 1)
		printf("Error\nTo few arguments\n");
	if (a == 2)
		printf("Error\nTo much arguments\n");
	if (a == 3)
		printf("Error\nArgument is not a .ber file\n");
	if (a == 4)
		printf("Error\nThe map is not rectangular\n");
	if (a == 5)
		printf("Error\nThe map is not enclosed\n");
	if (a == 6)
		printf("Error\nMap without exit\n");
	if (a == 7)
		printf("Error\nMap with more than 1 exit\n");
	if (a == 8)
		printf("Error\nMap without collectibles\n");
	if (a == 9)
		printf("Error\nMap without starting position\n");
	if (a == 10)
		printf("Error\nMap with more than 1 starting position\n");
	if (a == 11)
		printf("Error\nMap have no reachable exit\n");
	if (a == 12)
		printf("Error\nMap with Exit no reachable\n");
	if (a == 13)
		printf("Error\nMap with invalid characters\n");
}

/*
void	exit_with_message_improved(t_data data, char *str, int i)
{
	ft_printf("%s", str);
	ft_freestr(data->mapstr);
	free(data->line_width);
	if (i == 2)
		ft_freestr(data->mapstrcopy);
	free(data);
	exit (0);
}
*/
