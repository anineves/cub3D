/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:09:44 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/02 16:10:41 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
/* int main ()
{
        int f;
        f = ft_isascii(265);
        printf("%d", f);
        return(0);
}
*/
