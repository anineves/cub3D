/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:47:10 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/07 15:50:56 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}

/*  bzero() apaga os dados nos n bytes do início da memória no local apontado
/por s, escrevendo zeros (bytes contendo '\0') naquela área. */

/* int main ()
{
        int s[3] = {3, 2, 4} ;

        printf("%d %d\n", s[0], s[1], s[2]);

        ft_bzero(s, 2 * sizeof(int));
        printf("%d %d\n", s[0], s[1], s[2]);
        return (0);
}
*/
