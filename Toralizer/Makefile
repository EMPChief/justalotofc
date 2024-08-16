
# Compiler and linker settings
CC = gcc
CFLAGS = -fPIC -shared -ldl -D_GNU_SOURCE

# Output file name
TARGET = toralizer.so

# Source files
SRCS = toralizer.c

# Build target
all: $(TARGET)

# Compile and link to create the shared object
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean up build artifacts
clean:
	rm -f $(TARGET)
