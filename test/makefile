# minimal makefile for SE class
all: test run

# main depends on all cpp files
test: $(patsubst %.cpp,%.o,$(filter-out ../main.cpp, $(wildcard ../*.cpp)) test.cpp)
	g++ --std=c++11 -Wall -o $@ $^

# a slightly ugly hack to make .o depend on .hpp if it exists
.SECONDEXPANSION:
%.o: %.cpp $$(wildcard $$*.hpp)
	g++ --std=c++11 -Wall -c -o $@ $<

run:
	./test

clean:
	rm test *.o