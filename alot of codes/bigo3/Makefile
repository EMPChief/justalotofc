# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -pedantic
LDFLAGS = -lcs50 -lm

# Automatically find all .c files and derive executable names
SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)

# Default target: Build all binaries
all: $(BINS)

# Rule to compile each .c file into a binary
%: %.c
	@echo "Compiling $< into $@..."
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# Rule to run each binary
run: $(BINS)
	@for bin in $(BINS); do \
		echo "Running $$bin..."; \
		./$$bin; \
	done

# Clean up generated files
clean:
	rm -f $(BINS)

# Phony targets
.PHONY: all clean run
