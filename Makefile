# Compiler
CC := gcc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I includes

# Directories
SRCDIR := src
OBJDIR := obj
BINDIR := .

# Source files
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Binary name
TARGET := push_swap

# Rules
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(BINDIR)/$(TARGET)

re: fclean all

.PHONY: all clean fclean re
