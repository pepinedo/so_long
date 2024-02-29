/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:08:54 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:18:42 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	flag(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	k;
	size_t	len;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	while (flag(set, s1[i]) && s1[i])
		i++;
	while (flag(set, s1[len - 1]) && (len - 1))
		len--;
	if (len < i)
		len = i;
	new = malloc(len - i + 1);
	if (new == 0)
		return (0);
	while (i < len)
		new[k++] = s1[i++];
	new[k] = '\0';
	return (new);
}
