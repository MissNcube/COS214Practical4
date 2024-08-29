# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pedantic 

# Define the target executable
TARGET = main

# Find all .cpp files and convert them to .o files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run with valgrind
run: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 2> valgrind_log.txt

# Run with gdb
debug: $(TARGET)
	gdb -ex run --args ./$(TARGET) 2>&1 | tee gdb_log.txt

# Clean up the build files
clean:
	rm -f $(OBJS) $(TARGET) valgrind_log.txt gdb_log.txt

# Phony targets
.PHONY: all run debug clean
