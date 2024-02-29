/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:09:20 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:18:52 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_tolower(int a)
{
	if (a >= 'A' && a <= 'Z')
		a = a + 32;
	return (a);
}

/*
int	main(void)
{
	char	c;
	char	d;

	c = 'M';
	d = 'n';
	printf("%d\n", ft_tolower(c));
	printf("%d\n", ft_tolower(d));
}
*/