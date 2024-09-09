# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pedantic 

# Define the targets for the different mains
TARGET_DEMO = demo
TARGET_TEST = test

# Find all .cpp files except the main files
SRCS = $(filter-out DemoMain.cpp TestingMain.cpp, $(wildcard *.cpp))

# Object files for each target
DEMO_OBJS = $(SRCS:.cpp=.o) DemoMain.o
TEST_OBJS = $(SRCS:.cpp=.o) TestingMain.o

# Default target (for 'make run')
run: $(TARGET_TEST)
	./$(TARGET_TEST)

# Target for TestingMain (default run)
$(TARGET_TEST): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TEST) $(TEST_OBJS)

# Target for DemoMain (for 'make run_demo')
$(TARGET_DEMO): $(DEMO_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_DEMO) $(DEMO_OBJS)

# Run the demo target
run_demo: $(TARGET_DEMO)
	./$(TARGET_DEMO)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(DEMO_OBJS) $(TEST_OBJS) $(TARGET_DEMO) $(TARGET_TEST)

# Phony targets
.PHONY: all run run_demo clean
