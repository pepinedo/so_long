/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:16:10 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 11:16:41 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	while (i < n)
	{
		if (dst1 || src1)
			dst1[i] = src1[i];
		i++;
	}
	return ((void *)dst1);
}

/*int main (void)
{
	char	*dst;
	char	*src;
	char	*res;

	dst = "Hola";
	src = "";
	res = memcpy(dst, src, 4);
	printf("%s\n", res);	
}
*/