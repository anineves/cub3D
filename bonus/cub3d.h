/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:20:14 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/20 00:06:10 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

#include <X11/X.h>
#include <X11/keysym.h>

#define TRANSPARENCY 0x00980088
#define WINDOW_WIDTH 1900
#define WINDOW_HEIGHT 1000
#define MLX_ERROR 1
#define RED_PIXEL 0x9ADB91
#define GREEN_PIXEL 0x964B00
#define PI 3.14159265358979323846
#define MAPX  8      //map width
#define MAPY  8      //map height
#define MAPS 64
#define MOVESPEED 0.08
#define ROTSPEED 0.05
#define MAPM 16

#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363
#define ESC 65307
#define SPACE 32

#define PCOIN "./assets/coin3.xpm"
#define PCOIN1 "./assets/coin.xpm"

#define BUTTON1_SELECTED_XPM "./assets/play2.xpm"
#define BUTTON1_XPM "./assets/play1.xpm"

#define BUTTON2_SELECTED_XPM "./assets/quit2.xpm"
#define BUTTON2_XPM "./assets/quit1.xpm"

#define BACKGROUND "./assets/CUB3D.xpm"
#define	BACKGROUND2 "./assets/background2.xpm"
//#define PCOIN "./assets/coin.xpm"
#define PDOOR "./assets/door.xpm"
#define SWORD1 "./assets/icon2.xpm"
#define SWORD2 "./assets/icon3.xpm"
#define SWORD3 "./assets/icon4.xpm"

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	COIN = 4,
	DOOR = 5,
	COIN1 = 6,
	SWORD = 7
};

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
	t_pos	size;
}	t_img;

typedef struct s_player
{
	char	dir;
	double	ang;
	double	px;
	double	py;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_ws;
	int		move_ad;
	int		has_moved;
	int		rotate;
	int		opendoor;
	t_img	**img_player;
}	t_player;

typedef struct s_map
{
	char		**file;
	char		**full;
	int			len;
	int			num_player;
	char		*north;
	int			n;
	char		*south;
	int			s;
	char		*west;
	int			w;
	char		*east;
	int			e;
	int			f;
	int			f_f;
	int			c;
	int			f_c;
	int			rows;
	int			rows_full;
	int			first_line;
	int			tex_x;
	int			tex_y;
	int			tex_index;
	double		pos;
	double		step;
	int			size_tex;
	int			nb_doors;
	t_pos		*door;
	int			is_door;
	t_pos		enemy;
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

typedef struct s_menu
{
	int			start_play;
	int			is_button_quit;
	int			is_button_play;
	t_img		button_p;
	t_img		button_q;
	t_img		menu;
	t_img		background;
	t_img		background2;
}	t_menu;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			**texture_pixels;
	int			**textures;
	int			clickmouse;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_img		north_img;
	t_img		south_img;
	t_img		west_img;
	t_img		east_img;
	t_img		coin_img;
	t_menu		menu;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

/*ft_init*/
void	init_ray(t_ray *ray);
void	init_img_clean(t_img *img);
void	init_data(t_data *data);

/*ft_init_player*/
void	player_info(t_data *data, int x, int y, char dir);
void	init_player_direction(t_data *data);
int		init_mlx(t_data *data);

/*ft_init_img*/
void		init_img(t_data *data, t_img *image, int width, int height);
t_img		ft_init_img(t_data *data);
int			init_texture_img(t_data *data, t_img *image, char *path);
void		init_textures(t_data *data);

/*get_file*/
void	ft_read_file(t_data *data, char *map_file);
void	create_map(t_data *data, int i);
void	get_file(t_data *data, char *map_file);

/*parsing_file_1*/
void	count_lines(t_data *data, char *file);
int		all_params(t_data *data);
int		parsing_file(t_data *data, char *line, int row);

/*parsing_file*/
void	ft_check_line(char *line, t_data *data, int y, int i);
void	validate_color(t_data *data, char *line, int i, int type);
char	*validate_texture(t_data *data, char *line, int i);

/*validate_map*/
void	validate_map(t_data *data);

/*dda*/
void	dda(t_ray *ray, t_player *player);
void	apply_dda(t_data *data, t_ray *ray);

/*ft_draw*/
void	draw_line(t_data *data, t_pos begin, t_pos end, int color);
int		render_rect(t_data *data, t_rect rect);
void	draw_player(t_data *data);
int		draw_map2d(t_data *data);
int		render(t_data *data);

/*raycasting*/
void	init_raycasting(int x, t_ray *ray, t_player *player);
int		raycasting(t_data *data);

//Render
void	render_images(t_data *data);

/*ft_move_buttons_1*/
void	move_a(t_data *data);
void	move_d(t_data *data);
void	move_w(t_data *data);
void	move_s(t_data *data);
void	rotate_right(t_data *data);

/*ft_move_buttons*/
void	rotate_left(t_data *data);
int		buttons(t_data *data);

/*events*/
int		rotate_mouse(int x, int y, t_data *data);
void	events(t_data *data);

/*events_mouse*/
int	mouse_menu_game(int x, int y, t_data *data);
int	mouse_menu(int x, int y, t_data *data);


/*ft_utils*/
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_free_map(char **map);
void	ft_free_textures3(t_data *data);
void	ft_free_textures(t_data *data);

/*ft_clean*/
void	ft_destroy_images(t_data *data);
void	ft_error(char *msg, t_data *data, int code);
int		ft_close(t_data *data);

/*ft_init_bonus*/
void    init_menu(t_menu *menu);

/*menu*/
void		is_button_play(t_data *data, int x, int y);
void		is_button_quit(t_data *data, int x, int y);
int			init_menu_img(t_data *data, t_img *image, char *path);
void    	menu(t_data *data);


void	fill_doors_positions(t_data *data);