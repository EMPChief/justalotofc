# Compiler and flags
CC = gcc
CFLAGS = -O2 -Wall

# Source files and corresponding binaries
SRCS = abitmoreadvancedquiz.c advancedquiz.c lastquiz.c newqui.c pointyquiz.c quiz.c quizy.c
BINS = $(SRCS:.c=)

# Default target: Build all binaries
all: $(BINS)

# Rule to compile each source file into a binary
%: %.c
	$(CC) $(CFLAGS) -o $@ $< -lm

# Clean up generated files
clean:
	rm -f $(BINS)

# Phony targets
.PHONY: all clean
