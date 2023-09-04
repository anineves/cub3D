#include "../cub3d.h"

void parsing_file(t_data *data, char *file)
{

    char	*map_t;
	char	*line;
	int		read;

	read = open(file, O_RDONLY);
	map_t = ft_calloc(sizeof(char), 1);
	//data->map.rows = 0;
	while (1)
	{
		line = get_next_line(read);

		if (line == NULL)
			break ;
        while(*line == ' ' || *line == '\t')

        if (ft_strncmp(line, "NO ", 3) == 0) {
            data->map.north = ft_strdup(line + 3);
        } else if (ft_strncmp(line, "SO ", 3) == 0) {
            data->map.south = ft_strdup(line + 3);
        } else if (ft_strncmp(line, "WE ", 3) == 0) {
            data->map.west = ft_strdup(line + 3);
        } else if (ft_strncmp(line, "EA ", 3) == 0) {
            data->map.east = ft_strdup(line + 3);
        } else if (ft_strncmp(line, "C", 1) == 0) {
            data->map.ceiling = ft_strdup(line + 2);
        } else if (ft_strncmp(line, "F", 1) == 0) {
            data->map.floor = ft_strdup(line + 2);
		free(line);
		//game->map.rows++;
	}
    }
	close(read);
	//ft_verific_line(map_t, game);
	data->map.file = ft_split(map_t, '\n');
	data->map.full = ft_split(map_t, '\n');
	free(map_t);
}