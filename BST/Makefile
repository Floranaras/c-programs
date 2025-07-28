# Minimal Makefile for BST project
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude
SRCDIR = src
OBJDIR = obj

# All source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = bst_program

# Default target
all: $(TARGET)

# Link all objects into executable
$(TARGET): $(OBJDIR) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Create obj directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compile .c files to .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Utility targets
clean:
	rm -rf $(OBJDIR) $(TARGET)

rebuild: clean all

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run
