/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:38:41 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/08 17:40:23 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
/* idêntica à função memcpy, mas garante um bom funcionamento */
/*int main ()
{
   char src[10] = "Escola 42";
   char dest[10] = "o";


   printf("Before memmove dest = %s\n", dest);
   memmove(dest, src, 9 * (sizeof(char)));
   printf("After memmoeve dest = %s\n", dest);

   char src1[10] = "Escola 42";
   char dest1[10] = "o";
   printf("Before ft_memmove dest = %s\n", dest1);
   ft_memmove(dest1, src1, 9 * (sizeof(char)));
   printf("After ft_memmove dest = %s\n", dest1);

   int arr1[] = {3, 4};
   int arr2[] = {1, 2};
   printf("Antes ft_memmove %d %d\n", arr2[0],arr2[1]);
   ft_memmove(arr2, arr1, 2 * sizeof(int));
   printf("Depois %d %d\n", arr2[0], arr2[1]);

   int arr3[] = {3, 4};
   int arr4[] = {1, 2};
   printf("Antes memmove %d %d\n", arr4[0], arr4[1]);
   memmove(arr4, arr3, 2 * sizeof(int));
   printf("Depois %d %d\n", arr4[0], arr4[1]);

   return(0);
} */
