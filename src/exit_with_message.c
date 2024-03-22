/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:32 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/11 16:54:34 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	exit (0);
}
