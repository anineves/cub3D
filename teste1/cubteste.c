#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./libft/libft.h"

#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define MLX_ERROR 1
#define RED_PIXEL 0xFFFFF1
#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64
#define GREEN_PIXEL 0x000001

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;


typedef struct s_map
{
	char		**full;
	//int			rows;
	//int			columns;
	t_position	p_player;
	t_position	p_exit;
}	t_map;

typedef struct s_player
{
    int p_x;
    int p_y;
    float   speed;
    float   angle;
    float   rotate_speed;
}   t_player;

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_map   map;
    t_player  *player;
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1)
	{
		return (NULL);
	}
	newstr = (char *)malloc (sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		newstr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		newstr[j++] = s2[i];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}


void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;

    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    //pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
    deltaX /= pixels; // 1
    deltaY /= pixels; // 0

    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        mlx_pixel_put(mlx, win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}

void draw_player(t_data *data, t_rect rect)
{
    int i;
    int j;

    /*i = rect.y  + 3*(rect.height/8);
        while (i < rect.y + 5*(rect.height/8))
        {
            j = rect.x + 3*(rect.width/8);
            while (j < rect.x + 5*(rect.width/8))
                mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0x00008B);
            ++i;
        }
    */
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0x00008B);
        ++i;
    }
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x + rect.width, rect.y, 0xFF8C00);
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x, rect.y + rect.height, 0xFF8C00);

}

int render_rect(t_data *data, t_rect rect, int x, int y)
{
    (void)x;
    (void)y;
    int	i;
    int j;

    if (data->win_ptr == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
        ++i;
    }
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x + rect.width, rect.y, 0xFF8C00);
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x, rect.y + rect.height, 0xFF8C00);
   /*if (data->map.full[x][y] == '2')
    {  
        data->player->p_x = x;
        data->player->p_y = y;
        printf("entrei");
        draw_player(data, rect);
    }*/
    return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    return (0);
}

/*int	render(t_data *data)
{
    render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
            100, 100, GREEN_PIXEL});
    render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});

    return (0);   if (key == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
}*/

void	ft_read_map(t_data *data, char *map_file)
{
	char	*map_t;
	char	*line;
	int		read;

	read = open(map_file, O_RDONLY);
	if (read == -1)
		printf("The map unable to open");
	map_t = ft_calloc(sizeof(char), 1);
	//data->map.rows = 0;
	while (1)
	{
		line = get_next_line(read);
		if (line == NULL)
			break ;
		map_t = ft_strjoin_free(map_t, line);
		free(line);
		data->player->angle += data->player->rotate_speed;//game->map.rows++;
	}
	close(read);
	//ft_verific_line(map_t, game);
	data->map.full = ft_split(map_t, '\n');
	free(map_t);
}



int drawMap2D(t_data *data)
{
     int x;
     int y;
     int xo;
     int yo;

     y = 0;
     while (y < mapY)
     {
         x = 0;
          while (x < mapX)
          {
              
               xo = x*mapS;
               yo = y*mapS;
               if (data->map.full[x][y] == '1')
			   		render_rect(data, (t_rect){xo, yo, mapS, mapS, GREEN_PIXEL}, x, y);
               else 
			   		render_rect(data, (t_rect){xo, yo, mapS, mapS, RED_PIXEL}, x, y);
                render_rect(data, (t_rect){(data->player->p_x),(data->player->p_y), 32, 32, 0x00008B}, x, y);
               x++;
          } 
          y++;
     } 
     return (0);
}

void move_player(t_data *data, int n)
{
    int newx;
    int  newy;
    newx = data->player->p_x + data->player->speed * cos(data->player->angle) * n;
    newy = data->player->p_y + data->player->speed * sin(data->player->angle) * n;

    //printf("entre %f\n" ,data->player->speed * sin(data->player->angle) * n);
    //printf("entre %f\n" ,data->player->speed * cos(data->player->angle) * n);
    if(data->map.full[newx/mapS][data->player->p_y/mapS]!= 0)
    {
        data->player->p_x = newx;
        printf("entre 1\n");
    }
    if(data->map.full[data->player->p_x/mapS][newy/mapS] != 0)
    {
        data->player->p_y = newy;
        printf("entrei 2\n");
    }
    printf("valor x %d, \n valor y %d \n", data->player->p_x, data->player->p_y);
}

int ft_update(int keysym, t_data *data)
{
    (void) data;
    if(keysym == 65361) //Left
        data->player->angle -= data->player->rotate_speed;
    if( keysym == 65363) //right
        data->player->angle += data->player->rotate_speed;
    
    //Esta a mover sem anglo 
    
    /*if (keysym == 119)//w
		move_player(data, 1);
	if (keysym == 115 )//s
    {
        move_player(data, -1);
        //data->player->p_x = 3;
        //data->player->p_y = 3;
	if (keysym == 97 )
    {

    }
	if (keysym == 100)//d
    {

    }
       if (keysym == 119)
    {
        data->player->p_y += 1;
    }*/
    if (keysym == 115 )//s
    {

        //move_player(data, -1);
        data->player->p_y -= 1;
    }
	if (keysym == 97 )
    {
        data->player->p_x -= 1;
    }
	if (keysym == 100)//d
    {
        data->player->p_x += 1;
    }
		
    return(0);
}

void init_player(t_data *data)
{
    data->player->speed = 0.1;
    data->player->angle = 0;
    data->player->rotate_speed = 0.02;
    data->player->p_x = 2*mapS;
    data->player->p_y = 3*mapS;

}
int	main(void)
{
    t_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
                                "my window");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }
    ft_read_map(&data, "1.cub");
    init_player(&data);
    drawMap2D(&data);
    mlx_hook(data.win_ptr, 02, (1L << 0), &ft_update, &data);
    mlx_hook(data.win_ptr, 12, (1L << 15), &drawMap2D, &data);
    mlx_loop_hook(data.mlx_ptr, &drawMap2D, &data);
    //mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &Buttons, &data);
    mlx_loop(data.mlx_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}

