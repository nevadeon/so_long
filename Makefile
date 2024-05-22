NAME = so_long

CC = cc
RM = rm -rf

CFLAGS += -Wall -Wextra -Werror -Iinclude
CLINKS = -ldl -lglfw -pthread -lm

LIBFT_FOLDER = lib
LIBFT = $(LIBFT_FOLDER)/libndav.a

LIB_FOLDER = lib
LIBMLX = $(LIB_FOLDER)/libmlx42.a

FILES = parsing/map_tests_1\
parsing/parse_inputs\
parsing/map_tests_2\
parsing/parse_map\
map/get_map\
map/map_utils\
map/map_tools\
errors\
graphics/image\
graphics/pixel\
graphics/sprite\
graphics/graphics_init\
graphics/graphics\
graphics/graphics_tools\
game/game_init\
game/menu_logic\
main\

SRC_FOLDER = src
OBJ_FOLDER = bin

SRC = $(addprefix $(SRC_FOLDER)/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_FOLDER)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(LIBFT) $(CLINKS)

$(LIBFT):
	make -C $(LIBFT_FOLDER)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FOLDER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: CFLAGS += -g
test: re
	gdb -tui ./$(NAME)

.PHONY: all bonus clear clean fclean re test