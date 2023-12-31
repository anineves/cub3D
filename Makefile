CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -g 
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lbsd -no-pie -fsanitize=address
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = cub3d

SRCS 	=./sources/ft_move_buttons.c 			./sources/ft_utils.c 					\
			./sources/ft_draw.c 				./sources/ft_map.c 						\
			./sources/ft_init_mlx.c				./sources/ft_init_player.c 				\
			./sources/ft_init.c 				./sources/ft_draw_rays.c				\
			./sources/ft_draw_rays_1.c													\
			./sources/ft_move_buttons_1.c		./sources/parsing_file.c 				\
			./sources/render.c					./sources/listen.c 							\
			main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE)  -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -lm -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
