# the compiler: gcc for C program, define as g++ for C++
CC := gcc

# compiler flags:
#-gadds debugging information to the executable file
#-Wall turns on most, but not all, compiler warnings
CFLAGS := -g -Wall

# the build target executable:
TARGET := matrix_generator
LIB := libreria

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(TARGET).c $(LIB).c -o $(TARGET)

clean:
	$(RM) $(TARGET) matrix.txt
