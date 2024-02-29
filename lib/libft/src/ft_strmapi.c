/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:58:20 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:18:20 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*as;

	as = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (as == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		as[i] = f(i, s[i]);
		i++;
	}
	as[i] = '\0';
	return (as);
}
