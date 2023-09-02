/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:32:08 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/09 14:42:47 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;

	if (!s1)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = (char *)malloc (sizeof(*s1) * (lens1 + lens2 + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		newstr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		newstr[j++] = s2[i];
	newstr[j] = '\0';
	return (newstr);
}
/* Aloca memoria e retorna uma nova string que e cancatenacao de
/ s1 com s2*/
/*
int             main()
{
        char *s1 = "Bom";
        char *s2 = "Dia";
        char *new;
        printf("%s\n%s\n", s1, s2);
        new = ft_strjoin(s1, s2);
        printf("%s\n", new);
        return (0);
}*/
