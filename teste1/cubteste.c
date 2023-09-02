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
#define RED_PIXEL 0xFFFFFF

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

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_map   map;
    t_position  pos_player;
}	t_data;

#define GREEN_PIXEL 0x000000

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64

/*int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,2,1,
 1,1,1,1,1,1,1,1,	
};*/

/*float degToRad(int a) 
{ 
    return a*PI/180.0;
}*/
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

int FixAng(int a)
{ 
    if(a>359)
    { 
        a-=360;
    } 
    if(a<0)
    { 
        a+=360;
    } 
    return a;
}

float px,py,pdx,pdy,pa;

int Buttons(int key, t_data *data)
{
    (void)data;
    if(key==97)
    { 
        pa+=5; 
        //pa=FixAng(pa); 
       // pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
    } 	
    if(key==100)
    { 
        pa-=5; 
        //pa=FixAng(pa);
        //pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
    } 
    if(key==119)
    { 
        px+=pdx*5; 
        py+=pdy*5;
    }
    if(key==115)
    { 
        px-=pdx*5; 
        py-=pdy*5;
    }

    return(0);
}

void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;

    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
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
    if (data->map.full[x][y] == 2)
    {
        
        draw_player(data, rect);
    }
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
               {
			   		render_rect(data, (t_rect){xo, yo,
                    mapS, mapS, GREEN_PIXEL}, x, y);
                    //printf("printe q verde valor x %d, valor y %d, valor xo %d, valor yo %d", x , y, xo, yo);
               }
               else 
               {
			   		render_rect(data, (t_rect){xo, yo, mapS, mapS, RED_PIXEL}, x, y);
                    //printf("printe q vermelho");
               }
               /*else
               { 
                    //render_rect(data, (t_rect){xo, yo, mapS, mapS, RED_PIXEL});
                    mlx_pixel_put(data->mlx_ptr, data->win_ptr, 8,8, 0x8B0000);
                    printf("pixel");
               }*/
               x++;
          } 
          y++;
     } 
     return (0);
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

    /* Setup hooks */ 
    ft_read_map(&data, "1.cub");
    mlx_loop_hook(data.mlx_ptr, &drawMap2D, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &Buttons, &data);

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}

