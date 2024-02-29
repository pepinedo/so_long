/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:34:25 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 12:41:15 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putunbr(unsigned int nbr, int i)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr < 0)
	{
		i += write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		i = ft_putunbr(nbr / 10, i++);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
		i++;
	}
	return (i);
}

/*
int main()
{
	unsigned int	nbr;

	nbr = -1;
	printf("%i", ft_putunbr(nbr, 0));
}
*/