/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:17:02 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:17:24 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(len);
	if (s2 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = (char)s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*int main (void)
{
	char	*s1;

	s1 = "JODER";
	printf("%s\n", ft_strdup(s1));
	return (0);
}*/