/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:46:13 by anaraujo          #+#    #+#             */
/*   Updated: 2023/08/31 23:05:56 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_map(t_data *data, char *map_file)
{
	char	*map_t;
	char	*line;
	int		read;

	read = open(map_file, O_RDONLY);
	//if (read == -1)
		//ft_handler_error("The map unable to open",da);
	map_t = ft_calloc(sizeof(char), 1);
	//data->map.rows = 0;
	while (1)
	{
		line = get_next_line(read);
		if (line == NULL)
			break ;
		map_t = ft_strjoin_free(map_t, line);
		free(line);
		//game->map.rows++;
	}
	close(read);
	//ft_verific_line(map_t, game);
	data->map.full = ft_split(map_t, '\n');
	free(map_t);
}
