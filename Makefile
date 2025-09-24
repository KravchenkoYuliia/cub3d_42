################################# DIRECTORIES ##################################
SRC_DIR = sources
BUILD_DIR = build
INCLUDE_DIR = includes
LIB_DIR = libs

################################## LIBRAIRIES ##################################
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_STATIC_LIB = $(LIBFT_DIR)/libft.a

GNL_DIR = $(LIB_DIR)/get_next_line
GNL_STATIC_LIB = $(GNL_DIR)/libftgnl.a

MLX_LINUX_DIR = $(LIB_DIR)/minilibx-linux
MLX_STATIC_LIB = $(MLX_LINUX_DIR)/libmlx.a
MLX_LINUX_STATIC_LIB = $(MLX_LINUX_DIR)/libmlx_Linux.a

LIBS =	$(GNL_STATIC_LIB) \
		$(LIBFT_STATIC_LIB)\
		$(MLX_STATIC_LIB) \
		$(MLX_LINUX_STATIC_LIB)

############################### COMPILER & FLAGS ###############################
CC = cc
IFLAGS =	-I $(LIBFT_DIR)/include \
			-I $(FT_PRINTF_DIR)/include \
			-I $(GNL_DIR)/include \
			-I $(MLX_LINUX_DIR) \
			-I $(INCLUDE_DIR)
# LDFLAGS = -lreadline -lncurses
MLX_FLAG = -lXext -lX11 -lm -lz -ldl -lglfw
GFLAG = -g3
CFLAGS = -Wall -Werror -Wextra $(IFLAGS)

############################# INPUT & OBJECT FILES #############################
SRC_FILES = ${SRC_DIR}/main.c \
${SRC_DIR}/parsing/check_args.c \
${SRC_DIR}/parsing/read_descriptional_file.c \
${SRC_DIR}/initialization/init_cub.c \
${SRC_DIR}/initialization/init_mlx.c \
${SRC_DIR}/hooks/hook.c \
${SRC_DIR}/the_end/exit.c

# Remove main.c from SRC_FILES to create a list of common files
COMMON_FILES = $(filter-out $(SRC_DIR)/main.c, $(SRC_FILES))
COMMON_OBJ_FILES = $(COMMON_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Object files - map source files to object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output Files
CUB3D_STATIC_LIB = libcub3d.a


VALG_FLAG	= valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --track-fds=yes --trace-children=yes \
				--suppressions=./readline.supp

################################## EXECUTABLE ##################################
EXEC = cub3D
MAIN_SRC = $(SRC_DIR)/main.c
MAIN_OBJ = $(BUILD_DIR)/main.o

#################################### COLORS ####################################
DEFAULT_COLOR = \033[0;39m
RED_COLOR = \033[0;91m
GREEN_COLOR = \033[0;92m
YELLOW_COLOR = \033[0;93m
BLUE_COLOR = \033[0;94m

#################################### RULES #####################################
all: $(EXEC)
	@echo "✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨"
	@echo "✨                  ✨✨                  ✨"
	@echo "✨    ./\___/\.     ✨✨     (\\(\\         ✨"
	@echo "✨                  ✨✨                  ✨"
	@echo "✨    ( >^ -^<)     ✨✨     ( -.-)       ✨"
	@echo "✨                  ✨✨                  ✨"
	@echo "✨    / ⊃ 🌸/       ✨✨     o_(\")(\")     ✨"
	@echo "✨                  ✨✨                  ✨"
	@echo "✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨"

$(LIBS):
	@$(MAKE) -C $(LIB_DIR) -s

$(CUB3D_STATIC_LIB): $(COMMON_OBJ_FILES)
	@ar rcs $@ $^
	@echo "$(GREEN_COLOR)Compiled: $(DEFAULT_COLOR) $(CUB3D_STATIC_LIB) ✅";

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW_COLOR)Compiling: $(DEFAULT_COLOR) $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(LIBS) $(CUB3D_STATIC_LIB) $(MAIN_OBJ)
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(CUB3D_STATIC_LIB) $(LIBS) $(MLX_FLAG) -o $@
	@echo "$(GREEN_COLOR)Executable: $(DEFAULT_COLOR)$(EXEC) created!✅"

debugger: CFLAGS += $(GFLAG)
debugger: fclean $(EXEC)

valgrind: $(EXEC)
	$(VALG_FLAG) ./$(EXEC)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN_COLOR)Clean: $(DEFAULT_COLOR) cub3d 🧹"

fclean: clean
	@rm -f $(CUB3D_STATIC_LIB) $(EXEC)
	@$(MAKE) fclean -C $(LIB_DIR) -s
	@echo "$(GREEN_COLOR)Fclean: $(DEFAULT_COLOR) cub3d 🧹"

re: fclean all

.PHONY: all clean fclean re debugger valgrind
