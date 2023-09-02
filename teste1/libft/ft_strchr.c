/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:47:56 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/08 16:43:40 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
//retorna a primeira ocorrencia em uma string
/* int main() 
{
    const char *str = "Olaa";
    char  c;
 
    c = 'b';
    printf("letra :%s \n", ft_strchr(str, c));
	
    const char *s = "Olaa";
    char  b;

    b = 'b';

    printf("letra :%s\n", strchr(s, b));
    return (0);
} */
