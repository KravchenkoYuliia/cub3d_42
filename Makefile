NAME = cub3D
CFLAGS = -Wall -Werror -Wextra $(INC_DIR)
MLX_FLAG = -lXext -lX11 -lm -lz -ldl -lglfw
LIBFT = libs/minilibx-linux/libmlx.a libs/libft/libft.a

all: $(LIBFT) $(NAME)
	@echo "✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨"
	@echo "✨                  ✨✨                   ✨"
	@echo "✨    ./\___/\.     ✨✨     (\\(\\        ✨"
	@echo "✨                  ✨✨                  ✨"
	@echo "✨    ( >^ -^<)     ✨✨     ( -.-)    ✨"
	@echo "✨                  ✨✨                   ✨"
	@echo "✨    / ⊃ 🌸/       ✨✨     o_(\")(\")     ✨"
	@echo "✨                  ✨✨                   ✨"
	@echo "✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨"

SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = -I includes -I libs/libft/includes

FILES = main.c initialization/init_win.c hooks/hook.c the_end/exit.c

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
O_DIRS = $(sort $(dir $(OBJ)))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@cc $(CFLAGS) -I/usr/include -Imlx_linux -I/opt/X11/include -I/opt -c $< -o $@

$(NAME): $(O_DIRS) $(OBJ)
	@cc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAG) -o $(NAME)

$(O_DIRS):
	@mkdir -p $@

$(LIBFT):
	@$(MAKE) -C libs/minilibx-linux -s
	@$(MAKE) -C libs/libft -s

clean:
	@$(MAKE) fclean -C libs/libft -s
	@$(MAKE) clean -C libs/minilibx-linux -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
re: fclean all
