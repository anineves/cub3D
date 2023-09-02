/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:33:50 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/09 14:04:12 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pt_dest;
	char	*pt_src;

	pt_dest = (char *)dest;
	pt_src = (char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		pt_dest[i] = pt_src[i];
		i++;
	}
	return (dest);
}
/* A função copia n bytes de *src para *dest.
/Funcao nao segura
*/
/*
int main ()
{
   char src[10] = "Escola 42";
   char dest[10] = "o";


   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, 9 * (sizeof(char)));
   printf("After memcpy dest = %s\n", dest);
   
   char src1[10] = "Escola 42";
   char dest1[10] = "o";

   printf("Before ft_memcpy dest = %s\n", dest1);
   ft_memcpy(dest1, src1, 9 * (sizeof(char)));
   printf("After ft_memcpy dest = %s\n", dest1);

   int arr1[] = {3, 4};
   int arr2[] = {1, 2};
   printf("Antes ft_memcpy %d %d\n", arr2[0],arr2[1]);
   ft_memcpy(arr2, arr1, 2 * sizeof(int));
   printf("Depois %d %d\n", arr2[0], arr2[1]);

   int arr3[] = {3, 4};
   int arr4[] = {1, 2};
   printf("Antes memcpy %d %d\n", arr4[0], arr4[1]);
   memcpy(arr4, arr3, 2 * sizeof(int));
   printf("Depois %d %d\n", arr4[0], arr4[1]);

   return(0);
}
*/
