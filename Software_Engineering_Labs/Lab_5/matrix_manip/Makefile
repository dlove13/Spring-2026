CC = gcc
CFLAGS = -Wall -g
TARGET = matrix

all: $(TARGET)

$(TARGET): matrix.o
	$(CC) $(CFLAGS) $^ -o $@

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) matrix.o
