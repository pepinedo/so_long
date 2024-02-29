/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:07:05 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:15:02 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isalnum(int a)
{
	return (ft_isalpha(a) || ft_isdigit(a));
}

/*
int main(void)
{
	char	c;
	char	d;
	char	e;

	c = 'A';
	d = '5';
	e = '-';
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", ft_isalnum(d));
	printf("%d\n", ft_isalnum(e));
}
*/