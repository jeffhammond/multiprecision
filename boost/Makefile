CXX 	 = clang++
CXXFLAGS = -g -Wall -std=c++11 -stdlib=libc++

LD	 = $(CXX)
LDFLAGS  = $(CXXFLAGS)

LIBS	 = -lmpfr -lgmp

all: horner-sine.x tgamma.x basic.x

%.x: %.o
	$(LD) $(LDFLAGS) $< $(LIBS) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f *.o *.x
