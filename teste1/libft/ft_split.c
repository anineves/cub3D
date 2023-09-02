/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:34:11 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/08 15:35:03 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**str;
	int		size;
	int		j;

	i = 0;
	j = 0;
	word = count_word(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (j < word)
	{
		while (s[i] == c)
			i++;
		size = size_word(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str)
			return (NULL);
		i += size;
		j++;
	}
	str[j] = 0;
	return (str);
}
/*Divide um string *s consoante um caracter ou sequência de caracteres
/e coloca cada fragmento numa nova posicao.*/
/*
int             main()
{
        char    str[] = "Ana  Neves  ff";
        char    **split;
        split = ft_split(str, ' ');
        printf("%s\n", split[0]);
        printf("%s\n", split[1]);
        printf("%s\n", split[2]);
        return (0);
} */
