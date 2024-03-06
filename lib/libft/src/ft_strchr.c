/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:22:07 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/05 13:22:56 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	ft_strchr(char *s, char c)
{
	unsigned int		i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

/*
int main (void)
{
	char	*s;

	s = "Holacaracola";
	printf("%s\n", ft_strchr(s, 'l'));
}
*/