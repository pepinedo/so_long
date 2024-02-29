/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:37:15 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:18:30 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && n + i <= len)
	{
		if (ft_strncmp(haystack + i, needle, n) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

/*
int main(void)
{
	char	*pajar;
	char	*aguja;

	pajar = "123456";
	aguja = "34";
	printf("%s\n", ft_strnstr(pajar, aguja, 6));
}
*/