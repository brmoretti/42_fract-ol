#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME				=	fractol
CC					=	cc
CC_FLAGS			=	-Wall	\
						-Wextra	\
						-Werror

#≻───░⋆ ✪ PROJECT DIRECTORIES & FILES ✪ ⋆░───────────────────────────────────≺#
SRC_DIR				=	src
INCLUDE_DIR			=	include
INCLUDE_FILES		=	fractol.h
INCLUDES			=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE_FILES))
BUILD_DIR			=	build
SRC_FILES			=	draw_fractal.c	\
						main.c			\
						mandelbrot.c	\
						rgba.c
SRCS				=	$(addprefix $(SRC_DIR)/, SRC_FILES)
OBJS				=	$(SRC_FILES:.c=.o)
BUILDS				=	$(addprefix $(BUILD_DIR)/, $(OBJS))

#≻───░⋆ ✪ MLX42 ✪ ⋆░─────────────────────────────────────────────────────────≺#

MLX42_REPO			=	https://github.com/codam-coding-college/MLX42.git
MLX42_LIB_NAME		=	libmlx42.a
MLX42_DIR			=	MLX42
MLX42_INCLUDE_DIR	=	$(MLX42_DIR)/include
MLX42_BUILD_DIR		=	$(MLX42_DIR)/build
MLX42_LIB			=	$(MLX42_BUILD_DIR)/$(MLX42_LIB_NAME)
MLX42_LIBS			=	-lmlx42		\
						-ldl		\
						-lglfw		\
						-pthread	\
						-lm
MLX42_CC			=	-I./$(MLX42_INCLUDE_DIR)	\
						-L./$(MLX42_BUILD_DIR)		\
						$(MLX42_LIBS)
#≻───░⋆ ✪ COLORS ✪ ⋆░────────────────────────────────────────────────────────≺#
RED					=	\033[0;31m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
MAGENTA				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
GREEN				=	\033[0;32m
DEFAULT 			=	\033[0:0m

#≻───░⋆ ✪ RULES ✪ ⋆░─────────────────────────────────────────────────────────≺#

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME)

$(NAME): $(MLX42_LIB) $(BUILD_DIR) $(BUILDS) $(INCLUDES)
	@ $(CC) -o $(NAME) $(BUILDS) -I./$(INCLUDE_DIR) $(MLX42_CC) -g

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $< -I./$(INCLUDE_DIR) -I./$(MLX42_INCLUDE_DIR) -o $@ -g

clean: clean_MLX
	@ rm -rf $(BUILD_DIR)

fclean: fclean_MLX clean
	@ rm -rf $(NAME)

test_MLX: $(MLX42_LIB)
	$(CC) -o test_MLX test_MLX.c $(MLX42_CC)

%_test: $(MLX42_LIB)
	$(CC) -o $@ $@.c $(MLX42_CC)

$(MLX42_LIB): $(MLX42_DIR)
	cd $(MLX42_DIR) && cmake -B build && \
	cmake --build build -j4

$(MLX42_DIR):
	git clone $(MLX42_REPO) $(MLX42_DIR)

clean_MLX:
	@if [ -d $(MLX42_BUILD_DIR) ]; then \
		find $(MLX42_BUILD_DIR) -mindepth 1 ! \
		-name '$(MLX42_LIB_NAME)' -exec rm -rf {} +; \
	fi

fclean_MLX:
	rm -rf $(MLX42_BUILD_DIR)

clear_MLX:
	rm -rf $(MLX42_DIR)
