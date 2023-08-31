CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lbsd
RM = rm -rf
NAME = cub3d

SRCS 			=  cubteste.c	

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE)  -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -lm -o $(NAME)

clean:
	$(MAKE) clean -C
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C 
	$(RM) $(NAME)
re: fclean all
