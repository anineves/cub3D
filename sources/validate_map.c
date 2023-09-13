/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:01:44 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/13 19:07:48 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_ver_firstlastline(t_data *data, int i)
{
	int	k;

	k = 0;
	while (data->map.full[i][k] == '\0')
	{
		if (data->map.full[i][k] == ' ' || data->map.full[i][k] == '1')
			k++;
		else
			return (1);
	}
	return (0);
}

void	ft_verific_walls(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.rows - data->map.first_line)
	{
		j = 0;
		while (data->map.full[i][j] == ' ')
			j++;
		if (data->map.full[i][j] != '1')
			ft_error("Isn't surrounded by walls\n", data);
		while (data->map.full[i][j] != '\0' && j < data->map.len)
		{
			if (data->map.full[i][j + 1] == ' ' && \
				data->map.full[i][j] != '1')
				ft_error("Isn't surrounded by walls\n", data);
			if (data->map.full[i][j + 1] == '\0' && \
				data->map.full[i][j] != '1')
				ft_error("Isn't surrounded by walls\n", data);
			if (data->map.full[i][j] == ' ' && (data->map.full[i - 1][j] == '0' \
					|| data->map.full[i + 1][j] == '0' ))
				ft_error("Isn't surrounded by walls\n", data);
			j++;
		}
	}
}

void	validate_map(t_data *data)
{
	int	i;

	i = data->map.rows - data->map.first_line;
	if (ft_ver_firstlastline(data, 0) == 1)
		ft_error("Isn't surrounded by walls\n", data);
	ft_verific_walls(data);
	if (ft_ver_firstlastline(data, i) == 1)
		ft_error("Isn't surrounded by walls\n", data);
}
