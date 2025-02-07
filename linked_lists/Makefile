CC = g++
STD = c++11

# Pattern rule for compiling .cpp files to .o files
build/%.o: %.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

# Rule for the test target
test: build/test_list

# Rule for linking the test_list executable
build/test_list: build/test_list.o
	$(CC) -o build/test_list build/test_list.o -std=$(STD)

# Rule for compiling test_list.o with dependency on LinkedList.h
build/test_list.o: test_list.cpp LinkedList.h
	@mkdir -p build
	$(CC) -c -o build/test_list.o test_list.cpp -std=$(STD)

# Phony targets
.PHONY: test clean

# Clean target to remove build directory and executable
clean:
	rm -rf build test_list