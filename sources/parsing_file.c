#include "../cub3d.h"

void ft_check_line(char *line, t_data *data)
{
	int i;
	
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||line[i] == 'P')
			data->map.num_player++;
		if (!ft_strchr("0 1NSWE", line[i]))
		{
			printf("Error invalid character '%c'\n", line[i]);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	
}


void create_map(t_data *data, int i)
{
	
	int j;
	int k;

	j=0;
	k=0;
	while(i < (data->map.rows ) && data->map.file && data->map.file[i])
	{	
		ft_check_line(data->map.file[i], data);
		data->map.full[k] = ft_calloc(ft_strlen(data->map.file[i])+1, sizeof(char));
		while (data->map.file[i][j] != '\0')
		{
			data->map.full[k][j] = data->map.file[i][j];
			j++;
		}
		printf("full line %d, %s\n", i, data->map.full[i-data->map.first_line]);
		printf("full line %d, %s\n\n", k, data->map.full[k]);
		j=0;
		i++;
		k++;
	}
	if(data->map.num_player != 1)
	{
		printf("ERROR, map must have one Player\n");
		exit (EXIT_FAILURE);
	}
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
