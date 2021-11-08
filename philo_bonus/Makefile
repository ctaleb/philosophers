CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm rf

INCS_PATH = inc/
INCS = philo_bonus.h

SRC_DIR = ./src/
SRC =	main.c			\
		init.c			\
		freeing.c		\
		checking.c		\
		mem_utils.c		\
		parsing_utils.c	\
		philo.c			\
		utils.c			\
		parsing.c		
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = philo_bonus

%.o: %.c $(INCS_PATH)$(INCS)
	$(CC) $(CFLAGS) -I $(INCS_PATH). -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ -I $(INCS_PATH). $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run