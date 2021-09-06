# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 13:49:47 by msanjuan          #+#    #+#              #
#    Updated: 2021/09/06 14:04:28 by msanjuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = server

SRCS = server.c \
		utils.c

OBJS = ${SRCS:.c=.o}

CC = clang
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o: ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all :		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re