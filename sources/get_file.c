/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:46:13 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 14:31:17 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_file(t_data *data, char *map_file)
{
	char	*line;
	int		read;
	int		i;
	int		j;

	i = 0;
	read = open(map_file, O_RDONLY);
	while (1)
	{
		j = 0;
		line = get_next_line(read);
		
		if (line == NULL && i == 0)
			ft_error("empty", data, 1);
		else if (line == NULL )
			break ;
		data->map.file[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		while (line[j] != '\0' && line[j] != '\n')
		{
			data->map.file[i][j] = line[j];
			j++;
		}
		data->map.file[i][j] = '\0';
		free(line);
		i++;
	}
	data->map.file[i] = NULL;
	close(read);
}

void	count_lines(t_data *data, char *file)
{

	int		fd;
	char	*line;


	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the file\n", data, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map.rows++;
		free(line);
	}
	close(fd);
}

int	all_params(t_data *data)
{
	if (data->map.n != 1 || data->map.s != 1 || data->map.w  != 1\
			|| data->map.e != 1 || data->map.f_c != 1\
			|| data->map.f_f != 1 || data->map.first_line == 0)
		ft_error("param", data, 1); 
	return (1);
}

void	create_map(t_data *data, int i)
{
	int	j;
	int	k;


	k = 0;
	while (i < (data->map.rows) && data->map.file && data->map.file[i])
	{
		j = 0;
		ft_check_line(data->map.file[i], data, i - data->map.first_line, i);
		data->map.full[k] = ft_calloc(data->map.len + 1, sizeof(char));
		if(data->map.file[i][0] == '\0' || data->map.file[i][0] == '\n'  )
			ft_error("empty line\n", data, 1);
		while (data->map.file[i][j] != '\0')
		{
			data->map.full[k][j] = data->map.file[i][j];
			j++;
		}
		while (j < (int)data->map.len)
        {
			if(data->map.file[i][0] == '\0' || data->map.file[i][0] == '\n'  )
            	data->map.full[k][j] = ' ';
            j++;
        }
		data->map.full[k][j] = '\0';
	
		i++;
		k++;
	}
	if (data->map.num_player != 1)
		ft_error("number of player must be one\n", data, 1);
}


void get_big_line(t_data *data, int i)
{
	int len;

	len = 0;
	while (i < data->map.rows)
	{
		len = ft_strlen(data->map.file[i]);
		if (len > data->map.len)
			data->map.len = len;
		data->map.rows_full++;
		i++;
	}
		
}

void	get_file(t_data *data, char *map_file)
{
	int		i;

	i = 0;
	count_lines(data, map_file);
	data->map.file = ft_calloc(data->map.rows + 1, sizeof(char *)); //libertar memoria disto
	ft_read_file(data, map_file);
	while (i < data->map.rows)
	{
		parsing_file(data, data->map.file[i], i);
		if (data->map.first_line != 0)
			break ;
		i++;
	}
	if (!all_params(data))
		ft_error("incomplete file\n", data, 1);
	get_big_line(data, i);
	data->map.full = ft_calloc((data->map.rows_full) + 1, \
								sizeof(char *));
	create_map(data, i);
	if (data->map.num_player != 1)
		ft_error("number of player must be one\n", data, 1);
	validate_map(data);
}
