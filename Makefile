#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
CC					=	cc
CC_FLAGS			=	-Wall	\
						-Wextra	\
						-Werror

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
#≻───────────────────────────────────────────────────────────────────────────≺#

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
	find $(MLX42_BUILD_DIR) -mindepth 1 ! -name '$(MLX42_LIB_NAME)' \
	-exec rm -rf {} +

fclean_MLX:
	rm -rf $(MLX42_BUILD_DIR)

clear_MLX:
	rm -rf $(MLX42_DIR)
