# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Wpedantic

# Source files
SRCS := main.c

# Object files
OBJS := $(SRCS:.c=.o)

# Executable name
TARGET := fib

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)