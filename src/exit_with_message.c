/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:32 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/06 16:06:18 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_with_message(int a)
{
	if (a == 1)
		printf("Error\nTo few arguments.\n");
	if (a == 2)
		printf("Error\nTo much arguments.\n");
	if (a == 3)
		printf("Error\nArgument is not a .ber file");
	if (a == 4)
		printf("Error\nThe map is not rectangular.");
	exit (0);
}