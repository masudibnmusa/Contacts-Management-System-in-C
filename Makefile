
## 2. Makefile

```makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = contacts
SRC = main.c

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Release build
release: CFLAGS += -O2
release: $(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) contacts.txt

# Install (copy to /usr/local/bin on Unix-like systems)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all debug release clean install uninstall run
