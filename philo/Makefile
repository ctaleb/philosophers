CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
VALS = 4 410 200 200 5
RM = rm -rf

INCS_PATH = inc/
INCS = philo.h

SRC_DIR = ./src/
SRC = main.c \
		checking.c \
		init.c \
		mem_utils.c \
		parsing_utils.c \
		parsing.c \
		philo.c \
		utils.c \
		freeing.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = philo

%.o: %.c $(INCS_PATH)$(INCS)
	$(CC) $(CFLAGS) -I $(INCS_PATH). -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ -I $(INCS_PATH). $(OBJS)

run: all
	./$(NAME) $(VALS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re run