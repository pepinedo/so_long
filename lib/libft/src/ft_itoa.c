/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:51:24 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:15:21 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	f_lenint(long int n)
{
	long int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}	
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	len;
	long int	new_n;

	new_n = n;
	len = f_lenint(new_n);
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	if (new_n == 0)
		str[0] = '0';
	str[len--] = '\0';
	if (new_n < 0)
	{
		str[0] = '-';
		new_n = new_n * (-1);
	}
	while (new_n > 0)
	{
		str[len] = (new_n % 10) + '0';
		new_n = new_n / 10;
		len--;
	}
	return (str);
}

/*
int main(void)
{
	int	i;
	
	i = 50;
	printf("%s\n", ft_itoa(i));
}
*/