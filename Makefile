CC	:= g++
CXXFLAGS:= -std=c++0x -Wall -Wno-sign-compare -Wno-deprecated-declarations -fpermissive -Wno-unknown-pragmas
LDFLAGS :=-ldl 

GTEST_DIR := googletest
GTEST_HEADERS := $(GTEST_DIR)/googletest/include/gtest/ $(GTEST_DIR)/googletest/gtest/internal
GTFLAGS :=-lgtest -pthread
CLASSES := point.h sphere.h
.PHONY  := main test clean

main: 
	$(CC) $(CXXFLAGS) -o main $(CLASSES) main.cpp 

test: 
	$(CC) $(CXXFLAGS) -o test $(CLASSES) test.cpp $(GTEST_HEADERS) $(GTFLAGS) 

clean:
	rm -rf *.o *.gch *~ test main
