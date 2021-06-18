CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIB_PATH = libft/
LIB = libft.a

INCS_PATH = inc/
INCS = philo.h

SRC_DIR = ./src/
SRC = main.c \
		idk.c \
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = philo

%.o: %.c $(INCS_PATH)$(INCS)
	$(CC) $(CFLAGS) -I $(INCS_PATH). -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS) $(LIB_PATH)$(LIB)
	$(CC) $(CFLAGS) -o $@ -I $(INCS_PATH). $(OBJS) $(LIB_PATH)$(LIB)

$(LIB_PATH)$(LIB):
	make -C $(LIB_PATH)

clean:
	$(RM) $(OBJS)
	make -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re