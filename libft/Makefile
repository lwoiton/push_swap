# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 18:52:19 by lwoiton           #+#    #+#              #
#    Updated: 2023/07/22 06:33:36 by lwoiton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output file
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR)

# Directories
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incl

# Source Names
SRC_NAMES = ft_lstsize.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c \
            ft_atoi.c \
            ft_strtrim.c \
            ft_itoa.c \
            ft_strnstr.c \
            ft_printf/ft_printf.c \
            ft_printf/conversion_utils.c \
            ft_printf/print.c \
            ft_printf/print_int.c \
            ft_printf/print_utils.c \
            ft_lstadd_front.c \
            ft_memmove.c \
            ft_putnbr_fd.c \
            ft_memchr.c \
            ft_strrchr.c \
            ft_strchr.c \
            ft_lstlast.c \
            ft_strdup.c \
            ft_memcmp.c \
            get_next_line/get_next_line_utils.c \
            get_next_line/get_next_line.c \
            ft_substr.c \
            ft_tolower.c \
            ft_isalnum.c \
            ft_strlen.c \
            ft_isdigit.c \
            ft_calloc.c \
            ft_lstclear.c \
            ft_strjoin.c \
            ft_isprint.c \
            ft_strmapi.c \
            ft_lstmap.c \
            ft_split.c \
            ft_toupper.c \
            ft_strlcat.c \
            ft_bzero.c \
            ft_isalpha.c \
            ft_memset.c \
            ft_striteri.c \
            ft_isascii.c \
            ft_lstiter.c \
            ft_strlcpy.c \
            ft_memcpy.c \
            ft_putchar_fd.c \
            ft_strncmp.c \
            ft_lstdelone.c
		ft_lstnew.c \
            ft_lstadd_back.c \

# Source files
SRC_FILES = $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_NAMES))

# Object files
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_NAMES))

# Default target
all: $(NAME)

# Rule to build the archive file
$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $@/ft_printf
	mkdir -p $@/get_next_line

# Clean generated files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Clean and build everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
