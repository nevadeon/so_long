NAME := so_long

CC := cc

# Flags
CFLAGS = -Wall -Werror -Wextra -I$(INC_FOLDER) -I$(LIBFT_FOLDER)/$(INC_FOLDER)
LDFLAGS = -L$(LIBFT_FOLDER) -lndav -L$(LIB_FOLDER) -lmlx42 -ldl -lglfw -pthread -lm

# Directories
SRC_FOLDER := src
OBJ_FOLDER := obj
INC_FOLDER := include

# Sources and objects
SRC := $(shell find $(SRC_FOLDER) -type f -name "*.c")
OBJ := $(patsubst $(SRC_FOLDER)/%.c, $(OBJ_FOLDER)/%.o, $(SRC))

# Library
LIB_FOLDER := lib
LIBFT_FOLDER := $(LIB_FOLDER)/libndav
LIBFT := $(LIBFT_FOLDER)/libndav.a
LIBMLX := $(LIB_FOLDER)/libmlx42.a

# Tests
TEST_BIN := test_bin
TEST_FOLDER := tests

# Tests sources and objects
TEST_SRC := $(shell find $(TEST_FOLDER) -type f -name "*.c")
TEST_OBJ := $(patsubst $(TEST_FOLDER)/%.c, $(OBJ_FOLDER)/$(TEST_FOLDER)/%.o, $(TEST_SRC))
TEST_LINK_OBJ := $(filter-out $(OBJ_FOLDER)/main.o, $(OBJ)) $(TEST_OBJ)

# Tests flags
DEBUG_CFLAGS := -g
TEST_CFLAGS := -I$(TEST_FOLDER)/$(INC_FOLDER) -DINCLUDE_TEST_HEADER
VALGRIND_FLAGS := --quiet --leak-check=full --show-leak-kinds=all
GDB_FLAGS := --quiet --args

TEST_ARGS :=

# ============================================================================ #
#        Main rules                                                            #
# ============================================================================ #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@./update_progress_bar.sh "Compiling $(NAME):"

re: fclean all

clean:
	@rm -rf $(OBJ_FOLDER)

fclean: clean
	@rm -f $(NAME)

# ============================================================================ #
#        Library rules                                                         #
# ============================================================================ #

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_FOLDER)

libre:
	@$(MAKE) -s -C $(LIBFT_FOLDER) re

# ============================================================================ #
#        Test rules                                                            #
# ============================================================================ #

$(TEST_BIN): $(TEST_LINK_OBJ)
	@$(CC) $(CFLAGS) -o $@ $(TEST_LINK_OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ Binaire de test $(TEST_BIN) créé.\n$(RESET_COLOR)"

$(OBJ_FOLDER)/$(TEST_FOLDER)/%.o: $(TEST_FOLDER)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

test: CFLAGS += $(TEST_CFLAGS)
test: $(TEST_BIN)
	@printf "$(YELLOW)Lancement des tests...\n$(RESET_COLOR)"
	@./$(TEST_BIN)

valgrind: CFLAGS += $(DEBUG_CFLAGS)
valgrind: libtest re
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(TEST_ARGS)

gdb: CFLAGS += $(DEBUG_CFLAGS)
gdb: libtest re
	gdb $(GDB_FLAGS) ./$(NAME) $(TEST_ARGS)

libtest:
	@make -s -C $(LIBFT_FOLDER) test

.PHONY: all clean fclean lclean re libre libtest test valgrind gdb
