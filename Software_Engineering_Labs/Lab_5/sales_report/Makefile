# Define variables for compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Define exe name
TARGET = sales

all: $(TARGET)

$(TARGET): sales.o
	$(CC) $(CFLAGS) $^ -o $@

sales.o: sales.c sales.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) sales.o
