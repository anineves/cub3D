/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:14:22 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/09 14:32:11 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tam_src;
	size_t	tam_dst;

	if (size == 0)
		return (ft_strlen(src));
	tam_src = ft_strlen(src);
	tam_dst = ft_strlen(dst);
	j = tam_dst;
	i = 0;
	if (size < tam_dst)
		return (tam_src + size);
	while (src[i] && j < (size - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (tam_dst + tam_src);
}
/* se size for menor que src retorna o tam de src + size
/ senao concatena e retorna tam de dest mais tam de src */
/*
int main (void)
{
	char src[] = "Bom dia";
    char dest[] = "Ca va";
    printf("funcao %d \n", ft_strlcat(dest, src, 12));
    printf("%s \n", dest);
    char src2[] = "Bom dia";
    char dest2[] = "Ca va";
    printf("%lu \n", strlcat(dest2, src2, 12));
    printf("%s \n", dest2);
} */
