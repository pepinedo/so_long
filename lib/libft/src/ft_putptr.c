/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:31:48 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 12:41:09 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_puthexptr(char *base, unsigned long long nbr, int i)
{
	unsigned long long	len;

	len = (unsigned long long)ft_strlen(base);
	if (nbr >= len)
	{
		i = ft_puthexptr(base, nbr / len, i++);
		write(1, &base[nbr % len], 1);
		i++;
	}
	else if (nbr < len)
	{
		write(1, &base[nbr], 1);
		i++;
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	write(1, "0x", 2);
	return (ft_puthexptr("0123456789abcdef", (unsigned long long)ptr, 2));
}

/*
int	main(void)
{
	void *ptr;

	ptr = "Hola";
	printf("%i\n", ft_putptr(""));
	printf("%i\n", printf("%p", ""));
}*/