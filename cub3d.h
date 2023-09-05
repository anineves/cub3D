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
#define GREEN_PIXEL 0x000000
#define PI 3.14159265358979323846
#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64
#define MOVESPEED 0.5
#define rotSpeed 0.02

typedef struct s_player
{
    char	dir;
	double	px;
	double	py;
	double	dir_x; //direcao do player
	double	dir_y; //direcao do player
	double	plane_x; //camara plane vector
	double	plane_y;
	//int		move_x;
	//int		move_y;
	//int		has_moved;
	//int		rotate;
}	t_player;


typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_map
{
	char		**file;
	char		**full;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceiling;
	int			rows;
	int			first_line;
	//int			columns;
	t_player	p_player;
}	t_map;


typedef struct s_ray
{
	double	ra;
	double	ray_x;
	double	ray_y;
	double	camera_x;
	double	camera_y;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
{
    void	    *mlx_ptr;
    void	    *win_ptr;
    t_map       map;
    t_player    player;
	t_ray		ray;
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

void	init_data(t_data *data);
int		init_mlx(t_data *data);
void	init_ray(t_ray *ray);
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_read_file(t_data *data, char *map_file);

/*parsing*/
void	parsing_file(t_data *data, char *file, int row);
void	ft_parse(t_data *data);
int		all_params(t_data *data);
void create_map(t_data *data, int i);

/*Movements*/
void    move_a(t_data *data);
void    move_d(t_data *data);
void    move_w(t_data *data);
void    move_s(t_data *data);
void    rotate_right(t_data *data);
int 	buttons(int key, t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		not_hit_wall(t_data *data, double x, double y);
/*Draw*/
void 	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void 	draw_player(t_data *data, t_rect rect);
int 	draw_map2d(t_data *data);
int 	draw_rays2d(t_data *data);
int 	render_rect(t_data *data, t_rect rect, int x, int y);

void draw_rays2d_1(t_data *data);
void	init_raycasting(int x, t_ray *ray, t_player *player);

void	init_player_direction(t_data *data);
int 	FixAng(int a);
