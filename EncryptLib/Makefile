# Compiler settings
CC = gcc
CFLAGS = -O2 -Wall

# Output files
TEST_BIN = test
ARCFOUR_LIB = arcfour.so

# Source files
TEST_SRC = test.c
ARCFOUR_SRC = arcfour.c

# Object files
TEST_OBJ = test.o
ARCFOUR_OBJ = arcfour.o

# Build all targets
all: $(ARCFOUR_LIB) $(TEST_BIN)

# Build the test executable
$(TEST_BIN): $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_BIN) $(TEST_OBJ)

# Compile the test object file
$(TEST_OBJ): $(TEST_SRC)
	$(CC) -c $(CFLAGS) $(TEST_SRC)

# Build the arcfour shared library
$(ARCFOUR_LIB): $(ARCFOUR_OBJ)
	$(CC) $(ARCFOUR_OBJ) -o $(ARCFOUR_LIB) $(CFLAGS) -fPIC -shared -ldl -D_GNU_SOURCE

# Compile the arcfour object file
$(ARCFOUR_OBJ): $(ARCFOUR_SRC)
	$(CC) -c $(CFLAGS) $(ARCFOUR_SRC)

# Clean up generated files
clean:
	rm -f $(TEST_BIN) $(ARCFOUR_LIB) $(TEST_OBJ) $(ARCFOUR_OBJ)
