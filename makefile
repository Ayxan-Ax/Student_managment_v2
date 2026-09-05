
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
 
TARGET = student_manager
SRCS = main.c student.c
OBJS = $(SRCS:.c=.o)
 
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
 
%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS) $(TARGET) students.txt
 
.PHONY: all clean
 