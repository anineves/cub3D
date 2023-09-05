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
	printf("%d \n", data->map.rows);
	while (i < data->map.rows )
	{
		printf("%s\n", data->map.file[i]);
		parsing_file(data, data->map.file[i], i);
		if(data->map.first_line != 0)
			break;
		i++;
	}

	if(!all_params(data))
		printf("incomplete file \n");
	/*else
	{
		printf("N %s\n", data->map.north);
		printf("S %s\n", data->map.south);
		printf("F %s\n", data->map.floor);
		printf("E %s\n", data->map.east);
		printf("W %s\n", data->map.west);
		printf("C %s\n", data->map.ceiling);
		printf("1 %d\n", data->map.first_line);

	}*/
	//create_map(data, i);
}
