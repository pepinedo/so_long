/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:26:39 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:17:12 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_wordscount(const char	*s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != 0)
				j++;
		}
		i++;
	}
	if (j == 2)
		return (1);
	return (j);
}

static void	ft_freeall(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_splitaux(char **splits, char const *s, char c)
{
	int		i;
	int		start;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != 0)
			i++;
		if (start < i)
		{
			splits[j] = ft_substr(s, start, (i - start));
			if (splits[j] == NULL)
				ft_freeall(splits);
			j++;
		}
	}
	splits[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**splits;

	splits = (char **)malloc(sizeof(char *) * (ft_wordscount(s, c) + 1));
	if (splits == 0)
		return (0);
	ft_splitaux(splits, s, c);
	return (splits);
}
