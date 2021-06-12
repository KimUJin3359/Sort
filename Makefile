CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

INCDIR = ./includes/

SRCS = ./srcs/ft_stack.c \
	   ./srcs/ft_utils.c \
	   ./srcs/ft_main.c \
	   ./srcs/ft_pivot.c \
	   ./srcs/ft_solve.c \
	   ./srcs/ft_split.c \
	   ./srcs/ft_strlen.c \
	   ./srcs/ft_atoi.c

OBJS = ${SRCS:.c=.o}

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I ${INCDIR}

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean :
	rm ./srcs/*.o

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re
