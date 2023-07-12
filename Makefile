# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 17:15:14 by lwoiton           #+#    #+#              #
#    Updated: 2023/07/12 16:26:13 by lwoiton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output file
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR) -I$(LIB_DIR)/incl

# Directories
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incl
LIB_DIR = libft

# Source files
SRC_FILES = main.c \
            linked_list_utils.c \
            ft_sort_int_tab.c\

# Object files
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBFT = $(LIB_DIR)/libft.a

# Default target
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

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

