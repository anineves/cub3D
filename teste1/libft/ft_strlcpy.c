/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:26:17 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/08 16:48:44 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	f;

	f = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (f);
}
/*
int main()
{
	char dest[] = "Asjhgjh";
	char src[] = "So iskkkto";
	unsigned int res;
	
	res = ft_strlcpy(dest, src, 15);
	printf("String: %s; Return: %d\n", dest, res);
	char dest2[] = "Asjhgjh";
	char src2[] = "So iskkkto";
	res = strlcpy(dest2, src2, 15);
	printf("String: %s; Return: %d\n", dest2, res);
		
} */
