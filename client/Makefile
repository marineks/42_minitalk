# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 12:14:57 by msanjuan          #+#    #+#              #
#    Updated: 2021/09/06 14:18:12 by msanjuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

SRCS = client.c \
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