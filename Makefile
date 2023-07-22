# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 17:15:14 by lwoiton           #+#    #+#              #
#    Updated: 2023/07/18 14:16:16 by lwoiton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output file
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g
IFLAGS = -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR)


# Directories
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incl
LIB_DIR = libft

# Source files
SRC_FILES = 00_main.c \
            00_linked_list.c \
            00_rotate_operations.c \
            00_stack_operations.c \
            01_parse_input.c \
            02_analyse_ranks.c \
            04_calculate_rotations.c \
            05_read_ranks.c \
            06_calculate_costs.c \
            07_execute_sort.c \
            utils_display_linked_list.c

# Object files
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBFT = $(LIB_DIR)/libft.a

# Default target
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(DFLAGS) $(CFLAGS) $(IFLAGS) -o $@ $^

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c incl/push_swap.h | $(OBJ_DIR)
	$(CC) $(DFLAGS) $(CFLAGS) $(IFLAGS) -c -o $@ $<

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $@
	
# Rule to build the libft library	
$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

# Clean generated files
clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

# Clean and build everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

