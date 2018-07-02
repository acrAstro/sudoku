# Basic flags for the compiler
CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-O3 -std=c++14 -Wall -Wextra

# Names of the two executables
EXE=sudoku
TEST=test

# Source and object files for the program
SRCS = src/SudokuInput.cpp src/SudokuSolver.cpp
OBJS = src/SudokuInput.o src/SudokuSolver.o

# Driver scripts:
#   1) main.cpp is the main executable for the program
#   2) test.cpp is a test program for rapid evaluation of new functionality
PUZZLE_SRC = src/main.cpp
PUZZLE_OBJ = src/main.o
TESTER_SRC = src/test.cpp
TESTER_OBJ = src/test.o

# Default rule for building the project
all: puzzle test clean

# This rule builds the puzzle solver
puzzle: $(PUZZLE_OBJ) $(OBJS)
	$(CXX) -o $(EXE) $(PUZZLE_OBJ) $(OBJS)

# This rule just builds the test sript
test: $(TESTER_OBJ) $(OBJS)
	$(CXX) -o $(TEST) $(TESTER_OBJ) $(OBJS)

# This rule cleans up object files and the test executable, but leaves the main
# puzzle executable
clean:
	$(RM) $(OBJS) $(TESTER_OBJ) $(PUZZLE_OBJ)

# This rule deletes all object and executable files, resets the directory
new:
	$(RM) $(OBJS) $(TESTER_OBJ) $(PUZZLE_OBJ) $(EXE) $(TEST)
