NAME1	= server
NAME2	= client
SRCS	= $(shell find "." -name "*.c")
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : $(NAME1) $(NAME2)

$(NAME1) : ${OBJS}
	$(CC) $(CFLAGS) server.o -o $(NAME1)

$(NAME2) : ${OBJS}
	$(CC) $(CFLAGS) client.o -o $(NAME2)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME1} ${NAME2}

re : fclean all

.PHONY : all clean fclean re
