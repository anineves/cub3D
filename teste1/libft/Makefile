# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 12:18:19 by asousa-n          #+#    #+#              #
#    Updated: 2023/01/24 11:39:28 by asousa-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
       ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c\
       ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
	   ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_prt_char.c ft_prt_hexadecimal.c\
	   ft_prt_number.c ft_prt_string.c ft_prt_pointer.c ft_prt_unsigned.c\
	   get_next_line.c get_next_line_bonus.c get_next_line_utils.c  


OBJS = $(SRCS:.c=.o)

SRC_BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

bonus:	$(OBJS) $(BONUS_OBJS)
		ar -rcs $(NAME) $(BONUS_OBJS) $(OBJS)

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all