/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:13 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/07 16:53:43 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
/* Procura a primeira ocorrencia de uma caracter em n
/ caracteres. Retorna ponteiro
//se nao encontrar retorna NULL
*/

/* int main()
{
	int arr1[] = {1, 2};
	int arr2[] = {3, 4};
	if(ft_memchr(arr2, 4, sizeof(int) * 2) != NULL) {
		printf("found");
	}else{
		printf("Didnt find");
	}
	return(0);

} */
