CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -g 
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lbsd -no-pie #-fsanitize=address
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = cub3d
BONUS = cub3d_bonus

SRCS 	=./mandatory/sources/ft_move_buttons.c 			./mandatory/sources/ft_utils.c 			\
			./mandatory/sources/ft_draw.c 				./mandatory/sources/get_file.c 			\
			./mandatory/sources/ft_init_player.c 		./mandatory/sources/parsing_file_1.c 	\
			./mandatory/sources/ft_init.c 				./mandatory/sources/raycasting.c		\
			./mandatory/sources/ft_clean.c				./mandatory/sources/dda.c				\
			./mandatory/sources/ft_move_buttons_1.c		./mandatory/sources/parsing_file.c 		\
			./mandatory/sources/render.c				./mandatory/sources/events.c 			\
			./mandatory/sources/ft_init_img.c			./mandatory/sources/validate_map.c		\
			./mandatory/main.c

SRCS_BONUS 	=./bonus/sources/ft_move_buttons.c 			./bonus/sources/ft_utils.c 				\
			./bonus/sources/ft_draw.c 					./bonus/sources/get_file.c 				\
			./bonus/sources/ft_init_player.c 			./bonus/sources/parsing_file_1.c 		\
			./bonus/sources/ft_init.c 					./bonus/sources/raycasting.c			\
			./bonus/sources/ft_clean.c					./bonus/sources/dda.c					\
			./bonus/sources/ft_move_buttons_1.c			./bonus/sources/parsing_file.c 			\
			./bonus/sources/render.c					./bonus/sources/events.c 				\
			./bonus/sources/ft_init_img.c				./bonus/sources/validate_map.c			\
			./bonus/main.c
			
OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE)  -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -lm -o $(NAME)
	echo "\033[1m $(NAME) ready \033[0m"

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS)
	$(MAKE) -C ./libft
	$(MAKE)  -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) -lm -o $(BONUS)
	echo "\033[1m $(BONUS) ready \033[0m"
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean all

.SILENT: