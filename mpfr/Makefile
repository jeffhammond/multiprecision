CXX 	 = clang++
CXXFLAGS = -g -Wall

LD	 = $(CXX)
LDFLAGS  = $(CXXFLAGS)

LIBS	 = -lmpfr -lgmp

all: test.x

test.x: test.o
	$(LD) $(LDFLAGS) $< $(LIBS) -o $@

test.o: test.cc SuperFloat.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f test.o test.x
