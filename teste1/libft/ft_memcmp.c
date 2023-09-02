/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:41:56 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/03 13:14:51 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt_string1;
	unsigned char	*pt_string2;

	pt_string1 = (unsigned char *)s1;
	pt_string2 = (unsigned char *)s2;
	i = 0;
	while (i < n && pt_string1[i] == pt_string2[i])
		i++;
	if (i == n)
		return (0);
	return (pt_string1[i] - pt_string2[i]);
}
/*  A função compara os primeiros n bytes de *s1 e *s2. 
//Retorna um valor que indica a sua relação (<0 se s1 é menor que s2;
//=0 se s1 é igual a s2;  >0 se s1 é maior s2).*/
/*int main ()
{
	int arr1[] = {1, 2};
	int arr2[] = {1, 3};
	int arr3[] = {1, 2, 3, 8};
	int arr4[] = {1, 2, 3, 9};

	
	printf("%d", ft_memcmp(arr1, arr2, 2 * sizeof(int)));
	printf("%d\n", memcmp(arr1, arr2, 2 * sizeof(int)));

	printf("%d", ft_memcmp(arr3, arr4, 3 * sizeof(int)));
	printf("%d\n", memcmp(arr3, arr4, 3 * sizeof(int)));
	
	printf("%d", ft_memcmp(arr3, arr2, 3 * sizeof(int)));
	printf("%d\n", memcmp(arr3, arr2, 3 * sizeof(int)));

	printf("%d", ft_memcmp(arr2, arr4, 3 * sizeof(int)));
	printf("%d\n", memcmp(arr2, arr4, 3 * sizeof(int)));

	return (0);
} */
