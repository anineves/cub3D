#include "../cub3d.h"

void ft_check_line(char *line, t_data *data, int y)
{
	(void) y;
	int i;
	
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||line[i] == 'P')
		{
			//data->player.px = i * mapS + mapS/2;
			//data->player.py = y * mapS + mapS/2;
			//data->player.dir = line[i];
			data->map.num_player++;
		}
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
		ft_check_line(data->map.file[i], data, i - data->map.first_line);
		data->map.full[k] = ft_calloc(ft_strlen(data->map.file[i])+1, sizeof(char));
		while (data->map.file[i][j] != '\0')
		{
			data->map.full[k][j] = data->map.file[i][j];
			j++;
		}
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

void validate_color(t_data *data, char *line, int i, int type)
{
	int		len;
	int		comma;
	int		r;
	int		g;
	int		b;
	char	**colors;

	comma = 0;
	r = 0;
	g = 0;
	b = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	len = i;
	while (line[len] != '\0' && line[len] != ' ' && line[len] != '\t')
	{
		if(line[len] == ',')
			comma++;
		len++;	
	}
	if (comma != 2)
	{
		printf("Error, color");
		exit(EXIT_FAILURE);
	}
	colors = ft_split(line, ',');
	printf("c0 %s\n", colors[0]);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free(colors);
	printf("r %d\n", r );
	printf("b %d\n", g );
	printf("b %d\n", b );
	if (r < 0 || r > 255 || g < 0 || g >255 || b < 0 || b >255)
	{
		printf("Error, one color");
		exit(EXIT_FAILURE);
	}
	if (type == 1)
	{
		data->map.ceiling = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		printf("ceiling %02x \n\n\n\n\n\n\n", data->map.ceiling);
	}
	if (type == 2)
	{
		data->map.floor = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		printf("floor %02x \n\n\n\n\n\n\n", data->map.floor );
	}
}

char *validate_texture(char *line, int i)
{
	int		len;
	char	*textura;
	int		j;

	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	len = i;
	while (line[len] != '\0' && (line[len] != ' ' && line[len] != '\t'))
		len++;
	textura = malloc(sizeof(char) * (len - i + 1));
	if (!textura)
		return (NULL);
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		textura[j++] = line[i++];
	textura[j] = '\0';
	len = ft_strlen(textura);
	if (!ft_strnstr(&textura[len - 4], ".xpm", 4))
	{
		printf("Error, incorrect texture's path");
		exit(EXIT_FAILURE);
	}
	return (textura);
}


void parsing_file(t_data *data, char *line, int row)
{

	(void) row;

	int i;
	i = 0;
        while(line[i] == ' ' || line[i] == '\t')
			i++;
        if (ft_strncmp(line + i, "NO ", 3) == 0) 
            data->map.north = validate_texture(line, i + 3);
        else if (ft_strncmp(line + i , "SO ", 3) == 0) 
            data->map.south = validate_texture(line, i + 3);
        else if (ft_strncmp(line + i, "WE ", 3) == 0)
            data->map.west = validate_texture(line, i + 3);
        else if (ft_strncmp(line + i, "EA ", 3) == 0)
            data->map.east = validate_texture(line, i + 3);
        else if (ft_strncmp(line + i, "C ", 2) == 0)
            validate_color(data, line+ i + 2 , i + 2, 1);
        else if (ft_strncmp(line + i, "F ", 2) == 0)
            validate_color(data, line+ i + 2 , i + 2, 2);
		else if (line[i] == '0' || line[i] == '1')
			data->map.first_line = row;
		else if (line[i] != '\0')
		{
			printf("Error invalid line\n");
			exit (EXIT_FAILURE);
		}
}
