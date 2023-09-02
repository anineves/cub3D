/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:54:14 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/03 15:31:51 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = c;
		i++;
	}
	return (s);
}

/* preenche todos os primeiros cn bytes de*dest com o valor c (0-255). 
//Retorna dest.*/
/*
int main ()
{
        int arr1[] = {3, 4};
        printf("%d %d\n", arr1[0], arr1[1]);
        ft_memset(arr1, 0, 2 * sizeof(int));
        printf("%d %d\n", arr1[0], arr1[1]);

        int arr2[] = {3, 4};
        printf("%d %d\n", arr2[0], arr2[1]);
        memset(arr2, 0, 2 * sizeof(int));
        printf("%d %d\n", arr2[0], arr2[1]);


        return (0);
} */
