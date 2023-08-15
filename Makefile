# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 17:15:14 by lwoiton           #+#    #+#              #
#    Updated: 2023/08/15 13:10:35 by lwoiton          ###   ########.fr        #
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
BNS_DIR = bonus
INC_DIR = incl
LIB_DIR = libft

# Source files
SRC_FILES = 00_linked_list.c \
            00_rotate_operations.c \
            00_stack_operations.c \
            01_main.c \
            02a_parse_input.c \
            02b_check_input.c \
            03_analyse_ranks.c \
            04_divide_into_chunks.c \
            05_sort_five.c \
            06a_calculate_rotations.c \
            06b_read_ranks.c \
            07_calculate_costs.c \
            08_execute_sort.c \
            utils_display_linked_list.c

BNS_FILES = 

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

# Rule to build the bonus executable (checker)
#bonus: $(OBJ_FILES) $(LIBFT)
#    $(CC) $(DFLAGS) $(CFLAGS) $(IFLAGS) -o checker $^

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

