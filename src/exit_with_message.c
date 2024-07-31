/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:32 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/07/31 13:07:08 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_starting_position_message(t_data *data, int p)
{
	if (p == 0)
		exit_with_message(data, "Error\nMap without starting position\n", 1);
	if (p > 1)
		exit_with_message(data, "Error\nMulti-start Map\n", 1);
}

void	check_if_have_exit_message(t_data *data, int e)
{
	if (e == 0)
		exit_with_message(data, "Error\nMap without exit\n", 1);
	if (e > 1)
		exit_with_message(data, "Error\nMap with more than 1 exit\n", 1);
}

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

void	exit_before_inicializate(char *str)
{
	ft_printf("%s", str);
	exit (0);
}

void	exit_with_message(t_data *data, char *str, int i)
{
	if (i == 3)
		ft_printf("✅ %s", str);
	else
		ft_printf("❎​ %s", str);
	if (i >= 1)
	{
		ft_freestr(data->mapstr);
		free(data->line_width);
	}
	if (i >= 2)
		ft_freestr(data->mapstrcopy);
	exit (0);
}
