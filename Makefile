NAME = 

CC = cc
RM = rm -f
CLONE = git clone --depth=1

CFLAGS += -Wall -Wextra -Werror -O3
CLINKS = -ldl -lglfw -pthread -lm

MLX = minilibx
LIBMLX = $(MLX)/libmlx42.a

SRC_FOLDER = src
SRC	=	$(SRC_FOLDER)/get_map.c\
		$(SRC_FOLDER)/main.c\
		$(SRC_FOLDER)/map_utils.c\
		$(SRC_FOLDER)/parse_errors_1.c\
		$(SRC_FOLDER)/parse_errors_2.c\
		$(SRC_FOLDER)/parse_map.c\
OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(MLX) 

re: fclean all

.PHONY: all bonus clear clean fclean re