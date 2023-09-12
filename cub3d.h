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

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 920
#define MLX_ERROR 1
#define RED_PIXEL 0xFFFFFF
#define GREEN_PIXEL 0x000000
#define PI 3.14159265358979323846
#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64
#define MOVESPEED 0.5
#define rotSpeed 0.05
#define mapM 16

#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363
#define ESC 65307

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_player
{
    char	dir;
	double	ang;
	double	px;
	double	py;
	double	dir_x; //direcao do player
	double	dir_y; //direcao do player
	double	plane_x; //camara plane vector
	double	plane_y;
	int		move_ws;
	int		move_ad;
	int		has_moved;
	int		rotate;
}	t_player;


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
	char		**map;
	int		len;
	int		num_player;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int		f;
	int		c;
	int			rows;
	int			first_line;
	int		tex_x;
	int		tex_y;
	int		tex_index;
	double		pos;
	double 		step;
	int		size_tex;
	//int			columns;
	t_player	p_player;
}	t_map;


typedef struct s_ray
{
	double	camera_x;
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
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	
}	t_ray;

typedef struct s_data
{
    void	    *mlx_ptr;
    void	    *win_ptr;
	int		**texture_pixels;
	int			**textures;
    t_map       map;
    t_player    player;
	t_ray		ray;
	t_img		text;
	t_img		north_img;
	t_img		south_img;
	t_img		west_img;
	t_img		east_img;

	}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;


/*init*/
void	init_data(t_data *data);
int		init_mlx(t_data *data);
void	init_ray(t_ray *ray);
void	init_texture_img(t_data *data, t_img *image, char *path);
void	init_img(t_data *data, t_img *image, int width, int height);
void	ft_read_file(t_data *data, char *map_file);
float	degToRad(int a) ;
void	init_img_clean(t_img *img);
void	set_image_pixel(t_img *image, int x, int y, int color);
void	player_info(t_data *data, int x, int y, char dir);

/*parsing*/
void	ft_check_line(char *line, t_data *data, int y, int i);
void	parsing_file(t_data *data, char *file, int row);
void	get_file(t_data *data, char *map_file);
int		all_params(t_data *data);
void	create_map(t_data *data, int i);
void	validate_map(t_data *data);

/*Movements*/
void    move_a(t_data *data);
void    move_d(t_data *data);
void    move_w(t_data *data);
void    move_s(t_data *data);
void    rotate_right(t_data *data);
int 	buttons(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		not_hit_wall(t_data *data, double x, double y);

/*mlx*/
t_img	ft_init_img(t_data *data);
unsigned int	get_type_wall(t_data *data, t_ray *ray);

/*Draw*/
void 	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
//void 	draw_player(t_data *data, t_rect rect);
void	draw_player(t_data *data, int x, int y);
int	draw_map2d(t_data *data);
//int 	draw_map2d(t_data *data);
int 	draw_rays2d(t_data *data);
int 	render_rect(t_data *data, t_rect rect, int x, int y);
void 	render_images(t_data *data);
void draw_rays2d_1(t_data *data);
void	init_raycasting(int x, t_ray *ray, t_player *player);
void	init_player_direction(t_data *data);
int 	FixAng(int a);
void	apply_dda(t_data *data, t_ray *ray);
void	dda(t_ray *ray, t_player *player);
int 	raycasting(t_data *data);


//Render
int render_mini(t_data *data);
int render(t_data *data);

void events(t_data *data);
void	init_textures(t_data *data);

/*utils*/
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_error(char *msg, t_data *data);
