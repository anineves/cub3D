/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:01:44 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 15:56:50 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_ver_firstlastline(t_data *data, int i)
{
	int	k;

	k = 0;
	while ((size_t)k < (ft_strlen(data->map.full[i]) - 1))
	{
		if (data->map.full[i][k] == ' ' || data->map.full[i][k] == '1')
			k++;
		else
			return (1);
	}
	return (0);
}

int	just_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_walls_line(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.rows_full)
	{
		j = 0;
		while (data->map.full[i][j] == ' ')
			j++;
		if (!just_space(data->map.full[i]) && data->map.full[i][j] != '1')
			ft_error("Isn't surrounded by walls 1\n", data, 1);
		while (data->map.full[i][j] != '\0' && j < data->map.len)
		{
			if (data->map.full[i][j + 1] == ' ' && \
				data->map.full[i][j] == '0')
				ft_error("Isn't surrounded by walls 2\n", data, 1);
			if (data->map.full[i][j + 1] == '\0' && \
				data->map.full[i][j] == '0')
				ft_error(" Isn't surrounded by walls3\n", data, 1);
			j++;
		}
	}
}

void	ft_space(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.rows_full)
	{
		j = 0;
		while (j < data->map.len)
		{
			if (data->map.full[i][j] == 32)
			{
				if (data->map.full[i][j + 1] && data->map.full[i][j + 1] == '0')
					ft_error("Invalid map 0", data, 1);
				if (j > 0 && data->map.full[i][j - 1] \
					&& data->map.full[i][j - 1] == '0')
					ft_error("Invalid map 0", data, 1);
				if (data->map.full[i + 1] && data->map.full[i + 1][j] == '0')
					ft_error("Invalid map 0", data, 1);
				if (i > 0 && data->map.full[i - 1][j] == '0')
					ft_error("Invalid map 0", data, 1);
			}
			j++;
		}
		i++;
	}
}

void	validate_map(t_data *data)
{
	int	i;

	i = data->map.rows - data->map.first_line - 1;
	ft_space(data);
	if (ft_ver_firstlastline(data, 0) == 1)
		ft_error("Isn't surrounded by walls\n", data, 1);
	ft_walls_line(data);
	if (ft_ver_firstlastline(data, i) == 1)
		ft_error("Isn't surrounded by walls\n", data, 1);
}
