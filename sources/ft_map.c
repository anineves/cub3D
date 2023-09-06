/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:46:13 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/06 17:17:09 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_file(t_data *data, char *map_file)
{
	char	*map_t;
	char	*line;
	int		read;

	read = open(map_file, O_RDONLY);
	map_t = ft_calloc(sizeof(char), 1);
	data->map.rows = 0;
	while (1)
	{
		line = get_next_line(read);

		if (line == NULL)
			break ;
		map_t = ft_strjoin_free(map_t, line);
		free(line);
		data->map.rows++;
	}
	close(read);
	data->map.file = ft_split(map_t, '\n');
	data->map.full = ft_split(map_t, '\n');
	ft_parse(data); //Se comentar aqui, fica sem parser
	free(map_t);
}



void	ft_parse(t_data *data)
{

	int		i;

	i = 0;
	while (i < data->map.rows )
	{
		parsing_file(data, data->map.file[i], i);
		if(data->map.first_line != 0)
			break;
		i++;
	}

	if(!all_params(data))
		printf("incomplete file \n");
	create_map(data, i);
}
