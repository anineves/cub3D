/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:32:44 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/09 16:13:40 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cont(int nb)
{
	int	cont;

	cont = 0;
	if (nb <= 0)
	{
		cont++;
	}
	while (nb != 0)
	{
		cont ++;
		nb = nb / 10;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	cont;
	size_t	sinal;

	cont = ft_cont(n);
	sinal = 1;
	str = malloc(sizeof(char) * (cont + 1));
	if (str == NULL)
		return (NULL);
	str[cont] = '\0';
	cont--;
	if (n < 0)
	{
		str[0] = '-';
		sinal = -1;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[cont] = '0' + (n % 10 * sinal);
		n = n / 10;
		cont--;
	}
	return (str);
}

/* converte o inteiro em uma string terminada em nulo. Ele também 
/pode converter números negativos*/

/*
int     main(void)
{
        printf("%s\n", ft_itoa(1342345));
} */
