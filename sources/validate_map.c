/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:01:44 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 23:34:10 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_verific_walls(t_data *data)
{
	int i;
	int j;
	int space;

	i = 0;
	printf("Rows %d Len %d\n", data->map.rows, data->map.len);
	while (i < data->map.rows - data->map.first_line)
	{
		printf("%s\n", data->map.full[i]);
		j = 0;
		space = 0;
		while (data->map.full[i][j] == ' ')
		{
			j++;
			space = 1;
		}
		if (data->map.full[i][j] != '1')
        {
            ft_error("Isn't surrounded by walls\n", data);
			return;
        }
		while (j < data->map.len)
		{
			if ((data->map.full[i][j + 1] == ' ') && data->map.full[i][j] != '1')
			{
                ft_error("Isn't surrounded by walls\n", data);
			    return;
            }
			j++;
		}
		i++;
	}
}

void	validate_map(t_data *data)
{
	ft_verific_walls(data);
}