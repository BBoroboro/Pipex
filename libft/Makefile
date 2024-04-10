# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 17:05:33 by mamoulin          #+#    #+#              #
#    Updated: 2024/03/20 18:18:59 by mamoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_BASE = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strncmp.c \
       ft_strcmp.c \
       ft_atoi.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strnstr.c \
       ft_strdup.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_calloc.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_itoa.c \
       ft_free_tab.c	\
       get_next_line.c \
       get_next_line_utils.c

SRC_PRINTF = ft_printchar.c \
              ft_printu.c \
              ft_print_hex.c \
              ft_printhex_maj.c \
              ft_print_nbr.c \
              ft_printpc.c \
              ft_printptr.c \
              ft_printf.c \
              ft_printstr.c
SRC_BONUS = ft_lstnew.c \
	    ft_lstadd_front.c \
	    ft_lstsize.c \
	    ft_lstlast.c \
	    ft_lstadd_back.c \
	    ft_lstdelone.c \
	    ft_lstclear.c \
	    ft_lstiter.c \
	    ft_lstmap.c

SRCS = $(addprefix ./srcs/base/, $(SRC_BASE) $(SRC_BONUS)) \
       $(addprefix ./srcs/printf/, $(SRC_PRINTF))

OBJ = ${SRCS:.c=.o}

NAME = libft.a
HEADER = libft.h
CC = cc
CPPFLAGS = -I./include
CFLAGS = -Wall -Wextra -Werror -g
OPTION = -I ${HEADER}
RM = rm -f
AR = ar rc
RN = ranlib

.c.o:
	${CC} $(CPPFLAGS) ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			${AR} ${NAME} ${OBJ}
			${RN} ${NAME}

all:		${NAME}

clean:
	${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

so:
	$(CC) -fPIC $(CFLAGS) $(SRC) $(SRCSBONUS)
	gcc -shared -o libft.so $(OBJ) ${OBJSBONUS}

.PHONY:	all bonus clean fclean re
