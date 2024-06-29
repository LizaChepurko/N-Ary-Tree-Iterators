
 # ID: 211548268
 # Mail: lizachep@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
LDFLAGS_GTEST = -lgtest -lgtest_main -lpthread
LDFLAGS_SFML = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = main.cpp PreOrder.cpp PostOrder.cpp InOrder.cpp BFS.cpp DFS.cpp Heap.cpp
TEST_SRCS = test_main.cpp test_preorder.cpp test_postorder.cpp test_inorder.cpp test_tree.cpp test_dfs.cpp test_bfs.cpp test_heap.cpp test_complex.cpp
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o) PreOrder.o PostOrder.o InOrder.o DFS.o BFS.o Heap.o

# Targets
MAIN = tree_app
TEST = tree_tests

all: $(MAIN) $(TEST)

# Main application
$(MAIN): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS_SFML)

# Tests (excluding main.o)
$(TEST): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS_GTEST)

# Compilation rules
%.o: %.cpp tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to build and run main
tree: $(MAIN)
	./$(MAIN)

# Rule to build and run tests
tests: $(TEST)
	./$(TEST)

# Clean up
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(MAIN) $(TEST)
