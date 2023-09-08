/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:46:13 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/06 18:35:24 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



void	ft_read_file(t_data *data, char *map_file)
{
	char	*line;
	int		read;
	int		i;
	int		j;
	int  len;

	i = 0;
	j = 0;
	len = 0;
	read = open(map_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(read);
		if (line == NULL)
			break ;
		data->map.file[i] = ft_calloc(ft_strlen(line)+1, sizeof(char));
		while (line[j] != '\0' && line[j] != '\n')
		{
			data->map.file[i][j] = line[j];
			j++;
		}
		//data->map.file[i][j] = '\0';
		j=0;
		free(line);
		i++;
	}
	data->map.file[i] = NULL;
	len = i;
	i = 0;
	while (i <= len)
	{
		printf("linha %d, %s\n", i, data->map.file[i]);
		i++;
	}
	close(read);
}

void count_lines(t_data *data, char *file)
{
	char *line;
	int		len;
	int		fd;

	len = 0;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error, open file");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = ft_strlen(line);
		if(len > data->map.len)
			data->map.len = len;
		data->map.rows++;
		free(line);
	}
	close(fd);
}

void	ft_parse(t_data *data, char *map_file)
{
	int		i;
	i = 0;
	
	count_lines(data, map_file);
	data->map.file = ft_calloc(data->map.rows + 1, sizeof(char *));
	ft_read_file(data, map_file);
	while (i < data->map.rows )
	{
		parsing_file(data, data->map.file[i], i);
		if(data->map.first_line != 0)
			break;
		i++;
	}
	if(!all_params(data))
		printf("incomplete file \n");
	data->map.full = ft_calloc((data->map.rows - data->map.first_line)+ 1, sizeof(char *));
	create_map(data, i);
	//validate_map(data);
	/*i =0;
	printf("mapa fullll\n");
	while (i <= data->map.rows - data->map.first_line)
	{
		printf("linha %d, %s\n", i, data->map.full[i]);
		i++;
	}*/
}
