/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:39:12 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/06 16:11:05 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_if_its_ber(char *fdmap)
{
	int	i;

	i = 0;
	while (fdmap[i])
		i++;
	if (fdmap[--i] != 'r' && fdmap[--i] != 'e' && fdmap[--i] != 'b'
		&& fdmap[--i] != '.')
		exit_with_message(3);
}

void	check_if_its_rectangular(t_data *data)
{
	int i;

	i = 0;
	while(i < (data->height - 1))
	{
		if (data->line_width[i] != data->line_width[i + 1])
			exit_with_message(4);
		i++;
	}
}