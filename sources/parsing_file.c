#include "../cub3d.h"

void ft_check_line(char *line)
{
	int i;
	
	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_strchr(" 01NSWE", line[i]))
		{
			printf("Error invalid character\n");
			exit (EXIT_FAILURE);
		}
		i++;
	}
	
}

void create_map(t_data *data, int i)
{
	
	char *map_t;

	map_t = ft_calloc(sizeof(char), 1);

	while(i < (data->map.rows -2))
	{	
		printf("rows %d\n", data->map.rows);
		printf("i %d\n", i);
		ft_check_line(data->map.file[i]);
		map_t = ft_strjoin_free(map_t, data->map.file[i]);
		i++;
	}
	data->map.full = ft_split(map_t, '\n');
	free(map_t);
}

int all_params(t_data *data)
{
	if(!data->map.north || !data->map.south || !data->map.west || !data->map.east 
			|| !data->map.floor || !data->map.ceiling || data->map.first_line == 0)
		return(0);
	return (1);
}

void parsing_file(t_data *data, char *line, int row)
{

	(void) row;

	int i;
	i = 0;
        while(line[i] == ' ' || line[i] == '\t')
			i++;
		if(line[i] == '\0')
			data->map.first_line = row;
        if (ft_strncmp(line + i, "NO ", 3) == 0) 
            data->map.north = ft_strdup(line + i + 3);
        else if (ft_strncmp(line + i , "SO ", 3) == 0) 
            data->map.south = ft_strdup(line + i + 3);
        else if (ft_strncmp(line + i, "WE ", 3) == 0)
            data->map.west = ft_strdup(line + i + 3);
        else if (ft_strncmp(line + i, "EA ", 3) == 0)
            data->map.east = ft_strdup(line + i + 3);
        else if (ft_strncmp(line + i, "C ", 2) == 0)
            data->map.ceiling = ft_strdup(line + i + 2);
        else if (ft_strncmp(line + i, "F ", 2) == 0)
            data->map.floor = ft_strdup(line + i + 2);
		else if (line[i] == '0' || line[i] == '1')
			data->map.first_line = row;
		else if (line[i] != '\0')
		{
			printf("Error invalid line\n");
			exit (EXIT_FAILURE);
		}
}
