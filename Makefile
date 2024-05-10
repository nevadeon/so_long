NAME = so_long

CC = cc
RM = rm -rf

CFLAGS += -Wall -Wextra -Werror -Iinclude -g
CLINKS = -ldl -lglfw -pthread -lm

LIBFT_FOLDER = lib
LIBFT = $(LIBFT_FOLDER)/libndav.a

LIB_FOLDER = lib
LIBMLX = $(LIB_FOLDER)/libmlx42.a

FILES = sprite\
map/get_map\
map/map_utils\
map/map_tools\
image_utils\
main\
image\
errors\
graphics\
parsing/parse_inputs\
parsing/map_tests_2\
parsing/parse_map\
parsing/map_tests_1\

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

.PHONY: all bonus clear clean fclean re