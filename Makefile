CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
NAME			= get_next_line.a
SOURCES			= get_next_line.c get_next_line_utils.c
SOURCES_BONUS	= get_next_line_bonus.c get_next_line_utils_bonus.c
HEADER			= get_next_line.h
INCLUDES		= -I.
OBJECTS			= $(SOURCES:.c=.o)
OBJECTS_BONUS	= $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
