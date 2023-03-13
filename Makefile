# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/03/13 21:03:45 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 		= allok.c freek.c init_trashcan.c
OBJS 		= ${SRCS:.c=.o}
NAME 		= trashcan.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

.c.o 	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
all 	: $(NAME)

$(NAME)	: ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME} 

re		: fclean all

test	: $(NAME)
		gcc ${CFLAGS} -o test main.c $(NAME) && ./test