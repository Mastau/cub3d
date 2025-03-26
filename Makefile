NAME = cub3d
CC = cc
LIBFT_PATH = lib/Libft
MLX_PATH = lib/MacroLibX
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.so
CFLAGS = -Werror -Wall -Wextra
LDFLAGS = -lm -lSDL2
DIROBJS = .objs
OBJS = $(SRCS:%.c=$(DIROBJS)/%.o)
HEADER = -I $(LIBFT_PATH) -I $(MLX_PATH)/includes -I headers/
SRCS =	sources/main.c \
		sources/parsing/check_av.c \
		sources/algo/init_player.c \
		sources/algo/degree_to_radian.c \
		sources/algo/ray_cast.c \
		sources/algo/init_ray_steps.c \
		sources/algo/calculate_intersection.c \
		sources/algo/get_player_orientation.c \
		sources/macro/hook.c \
		sources/macro/moves.c \
		sources/macro/rotates.c \
		sources/rendering/draw_vertical_line.c \
		sources/rendering/rendering.c \
		sources/rendering/init.c \
		sources/rendering/init2.c \
		sources/rendering/determine_wall_orentation.c \
		sources/rendering/render_3d_view.c \
		sources/rendering/load_textures.c \
		sources/utils/convert_rgb_str_to_color.c \
		sources/parsing/cells.c \
		sources/parsing/color.c \
		sources/parsing/map.c \
		sources/parsing/parsing.c \
		sources/parsing/path.c \
		sources/parsing/utils.c \
    	fake_data.c # ! A supprimer pour le rendu

# Couleurs et emojis
RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
RESET := \033[0m
SUCCESS_EMOJI := ✅
CLEAN_EMOJI := 🗑️
BUILD_EMOJI := 🛠️

# Commandes
RM := rm -rf
DIR_UP = mkdir -p $(@D)
MAKEFLAGS += --no-print-directory

all: init $(NAME)

init:
	@if [ ! -d "$(LIBFT_PATH)" ] || [ ! -d "$(MLX_PATH)" ]; then \
		echo "$(YELLOW)$(BUILD_EMOJI) Initializing submodules...$(RESET)"; \
		git submodule init; \
		git submodule update; \
	fi

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(YELLOW)$(BUILD_EMOJI)  Final compilation in progress...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) $(HEADER) -o $@
	@echo "$(GREEN)$(SUCCESS_EMOJI)  Compilation complete!$(RESET)"

$(DIROBJS)/%.o: %.c
	@$(DIR_UP)
	@echo "$(YELLOW)$(BUILD_EMOJI)  Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)$(BUILD_EMOJI)  Compiling Libft...$(RESET)"
	@make -C $(LIBFT_PATH)
	@echo "$(GREEN)$(SUCCESS_EMOJI)  Libft compiled!$(RESET)"

$(MLX):
	@echo "$(YELLOW)$(BUILD_EMOJI)  Compilation de la MLX...$(RESET)"
	@make -C $(MLX_PATH) -j
	@echo "$(GREEN)$(SUCCESS_EMOJI)  MLX compiled !$(RESET)"

clean:
	@$(RM) $(DIROBJS)
	@if [ -d "$(LIBFT_PATH)" ]; then \
        make -C $(LIBFT_PATH) clean; \
    fi
	@if [ -d "$(MLX_PATH)" ]; then \
        make -C $(MLX_PATH) clean; \
    fi
	@echo "$(RED)$(CLEAN_EMOJI)  Objets supprimés !$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@if [ -d "$(LIBFT_PATH)" ]; then \
        make -C $(LIBFT_PATH) fclean; \
    fi
	@if [ -d "$(MLX_PATH)" ]; then \
        make -C $(MLX_PATH) fclean; \
    fi
	@echo "$(RED)$(CLEAN_EMOJI)  Exécutable et librairies supprimés !$(RESET)"

re: fclean all

.PHONY: clean all re fclean init
