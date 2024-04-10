# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 16:03:47 by mamoulin          #+#    #+#              #
#    Updated: 2024/04/08 15:49:15 by mamoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = ./src/main.c \

SRC2 =	./src/initialize_data.c \
		./src/initialize_data2.c \
		./src/parsing.c \
		./src/path.c \
		./src/path2.c \
		./src/free_functions.c \
		./src/pipe.c \
		./src/fork.c \
		./src/handle_process.c \
		./src/open_files.c \

SRC_BONUS = ./src/main_bonus.c \
			

OBJ1 = ${SRC1:.c=.o}
OBJ2 = ${SRC2:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

NAME = pipex
BONUS = pipex_bonus
HEADER = pipex.h
LIBFT = ./libft/
LIBFT_MAKE = Makefile
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
CPPFLAGS = -I$(LIBFT) -I./libft/include -I./include
RM = rm -f
AR = ar rc
INCLUDES = -I/usr/include

all:		${NAME}

.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o ${<:.c=.o} $(INCLUDES)

${NAME}:	${OBJ1} ${OBJ2}
		make -C ./libft
		$(CC) $(CFLAGS) $(CPPFLAGS) -L$(LIBFT) -o $(NAME) $(OBJ1) ${OBJ2} -lft

${BONUS}:	${OBJ2} ${OBJ_BONUS}
		make -C ./libft
		$(CC) $(CFLAGS) $(CPPFLAGS) -L$(LIBFT) -o $(BONUS) $(OBJ_BONUS) $(OBJ2) -lft

bonus:		${BONUS}

clean:
		${RM} ${OBJ1} ${OBJ2} ${OBJ_BONUS} 
		make clean -C ./libft


fclean:		clean
			${RM} ${NAME} ${BONUS}
			make fclean -C ./libft

re:		fclean all

.PHONY: all clean fclean re