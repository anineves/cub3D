/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:55:28 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/25 10:59:27 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_hexa(unsigned int number)
{
	size_t	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number = number / 16;
	}
	return (len);
}

void	ft_puthexa(unsigned int number, const char format)
{
	if (number >= 16)
	{
		ft_puthexa(number / 16, format);
		ft_puthexa(number % 16, format);
	}
	else
	{
		if (number <= 9)
			ft_prt_char(number + 48);
		else
		{
			if (format == 'x')
				ft_prt_char(number - 10 + 'a');
			else if (format == 'X')
				ft_prt_char(number - 10 + 'A');
		}
	}
}

int	ft_prt_hexadecimal(unsigned int number, const char format)
{
	if (number == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(number, format);
	return (ft_strlen_hexa(number));
}
