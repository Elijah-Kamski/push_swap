NAME				= push_swap
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

PUSH_SWAP_DIR = \
					$(SRC_DIR)aux/operations.c \
					$(SRC_DIR)aux/utils_array.c \
					$(SRC_DIR)aux/validations_and_errors.c \
					$(SRC_DIR)sort/sort_3_to_5.c \
					$(SRC_DIR)sort/radix.c \
					$(SRC_DIR)main.c

SRCS 				= $(PUSH_SWAP_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@echo "Build process started..."

$(LIBFT):
					@echo "Compiling libft..."
					@make -C ./libft -s
					@echo "Libft compilation completed."

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
#					@echo "Linking $(NAME)..."
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)
#					@echo "$(NAME) linked successfully."

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
#					@echo "Compiling $<..."
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@
#					@echo "$< compiled successfully."

clean:
					@echo "Cleaning object files..."
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft -s
					@echo "Object files cleaned."

fclean: 			clean
					@echo "Cleaning executables..."
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "Executables cleaned."

re: 				fclean all

.PHONY: 			start all clean fclean re