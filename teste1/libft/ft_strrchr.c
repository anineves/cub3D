/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:21:19 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/09 14:37:50 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
//Retorna ultima ocorrencia de um c em string
/* int main()
{
    const char *s = "uOlaa";
    char  c;

    c = 'b';
    printf("letra :%s\n", ft_strrchr(s, c));
    printf("letra :%s\n", strrchr(s, c));
    return (0);
}
*/
