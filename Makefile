NAME = cub3d
CC = cc
LIBFT = lib/Libft/libft.a
MLX = lib/MacroLibX/libmlx.so
FLAGS = -Werror -Wall -Wextra -g -lm
DIROBJS = .objs
OBJS = $(SRCS:%.c=$(DIROBJS)/%.o)
HEADER = -I lib/libft -I lib/MacroLibX/includes -I includes/
SRCS = src/main.c \

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -lSDL2 $(HEADER) -o $@ -lm
$(DIROBJS)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(HEADER) $< -c -o $@
$(LIBFT):
	make -C lib/libft/ 
$(MLX):
	make -C lib/MacroLibX/ -j
clean:
	@rm -rf $(DIROBJS)
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
