CC	:= g++
CXXFLAGS:= -std=c++0x -Wall -Wno-sign-compare -Wno-deprecated-declarations -fpermissive
LDFLAGS :=-ldl
GTFLAGS :=-lgtest -pthread
CLASSES := point.h sphere.h
.PHONY  := main test clean

main: 
	$(CC) $(CXXFLAGS) -o main $(CLASSES) main.cpp 

test: 
	$(CC) $(CXXFLAGS) -o test $(CLASSES) test.cpp $(GTFLAGS)

clean:
	rm -rf *.o *.gch *~ test main