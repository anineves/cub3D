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

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define MLX_ERROR 1
#define RED_PIXEL 0xFFFFFF
#define PI 3,14159265358979323846

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
    void	    *mlx_ptr;
    void	    *win_ptr;
    t_map       map;
    t_player    player;
}	t_data;

typedef struct s_player
{
    char	dir;
	double	px;
	double	py;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	//int		move_x;
	//int		move_y;
	//int		has_moved;
	//int		rotate;
}	t_player;

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

void	init_data(t_data *data);
void	init_mlx(t_data *data);
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_read_map(t_data *data, char *map_file);
int 	Buttons(int key, t_data *data);
int		handle_keypress(int keysym, t_data *data);
void 	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void 	draw_player(t_data *data, t_rect rect);
int 	render_rect(t_data *data, t_rect rect, int x, int y);
int 	drawMap2D(t_data *data);
void	init_player_direction(t_data *data);