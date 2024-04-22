NAME = so_long

CC = cc
RM = rm -rf

CFLAGS += -Wall -Wextra -Werror -Iinclude -g
CLINKS = -ldl -lglfw -pthread -lm

LIBFT_FOLDER = lib
LIBFT = $(LIBFT_FOLDER)/libndav.a

LIB_FOLDER = lib
LIBMLX = $(LIB_FOLDER)/libmlx42.a

FILES = map \
main \
map_utils \
parse_errors_1 \
parse_errors_2 \
parse_map \

SRC_FOLDER = src
OBJ_FOLDER = obj

SRC = $(addprefix $(SRC_FOLDER)/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_FOLDER)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FOLDER) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(LIBFT) $(CLINKS)

$(LIBFT):
	make -C $(LIBFT_FOLDER)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FOLDER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clear clean fclean re