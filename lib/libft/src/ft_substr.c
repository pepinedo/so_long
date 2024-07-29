/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:05:37 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/03/05 13:37:01 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	char	*subs;

	if (!s)
		return (0);
	if (start >= ft_strlen((char*)s))
		len = 0;
	if (ft_strlen((char*)s) - start < len)
		len = ft_strlen((char*)s) - start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}
