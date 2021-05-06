# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrochet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 16:01:43 by mrochet           #+#    #+#              #
#    Updated: 2021/05/03 15:04:43 by mrochet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRCS_PATH = ./srcs/
SRCS_NAME = analyse_map.c ft_free_split.c parse_fcr.c plan_tab.c \
			print_struct.c analyse_file.c create_rays.c main.c \
			parsing.c premier_pas_mlx.c structure.c

UTILS_PATH = ./utils/
LIB = ft_isalpha.c ft_lstadd_back.c \
		   ft_lstlast.c ft_memchr.c ft_putchar_fd.c \
		   ft_strchr.c ft_strlen.c ft_strtrim.c \
		   ft_atoi.c ft_isascii.c ft_lstadd_front.c \
		   ft_lstmap.c ft_memcmp.c ft_putendl_fd.c \
		   ft_strdup.c ft_strmapi.c ft_substr.c \
		   ft_bzero.c ft_isdigit.c ft_lstclear.c \
		   ft_lstnew.c ft_memcpy.c ft_putnbr_fd.c \
		   ft_strjoin.c ft_strncmp.c ft_tolower.c \
		   ft_calloc.c ft_isprint.c ft_lstdelone.c \
		   ft_lstsize.c ft_memmove.c ft_putstr_fd.c \
		   ft_strlcat.c ft_strnstr.c ft_toupper.c \
		   ft_isalnum.c ft_itoa.c ft_lstiter.c \
		   ft_memccpy.c ft_memset.c ft_split.c \
		   ft_strlcpy.c ft_strrchr.c

SRCS_LIB = $(addprefix $(UTILS_PATH),$(LIB))
SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

HEADER	= includes/cub3d.h

RM		=	rm -f
CC		=	gcc
FSAN	=	-g -fsanitize=address
#CFLAGS	=	-Wall -Werror -Wextra

${NAME}:
	@${CC} ${FSAN} ${SRCS} ${SRCS_LIB} libmlx.dylib ${CFLAGS} 
	@echo "Compilation Succes !"
	@./a.out map.cub 

all: ${NAME}

clean:
	@${RM}  ${OBJS}
	@echo "Clean Succes !"

fclean:		clean
	@${RM} ${NAME}

re:			fclean all
