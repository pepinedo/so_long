/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:44:34 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:18:36 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	a;
	char	*as;

	a = (char)c;
	i = 0;
	j = -1;
	as = (char *)s;
	while (as[i] != '\0')
	{
		if (as[i] == a)
			j = i;
		i++;
	}
	if (a == '\0')
		return (&as[i]);
	if (j != -1)
		return (&as[j]);
	return (0);
}

/*int main (void)
{
	char	*s;

	s = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	printf("%s\n", ft_strrchr(s, 'a'));
}*/