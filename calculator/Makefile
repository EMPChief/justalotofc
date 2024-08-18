# Compiler and flags
CC = gcc
CFLAGS = -O2 -Wall

# Program 1
PROG1_SRC = calcnr1.c
PROG1_BIN = calcnr1

# Program 2
PROG2_SRC = calcnr2.c
PROG2_BIN = calcnr2

# Default target: Build both programs
all: $(PROG1_BIN) $(PROG2_BIN)

# Rule to compile program 1
$(PROG1_BIN): $(PROG1_SRC)
	$(CC) $(CFLAGS) -o $(PROG1_BIN) $(PROG1_SRC) -lm

# Rule to compile program 2
$(PROG2_BIN): $(PROG2_SRC)
	$(CC) $(CFLAGS) -o $(PROG2_BIN) $(PROG2_SRC) -lm

# Clean up generated files
clean:
	rm -f $(PROG1_BIN) $(PROG2_BIN)

# Phony targets
.PHONY: all clean
