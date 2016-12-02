CXX 	 = g++-6
CXXFLAGS = -g -Wall -std=gnu++11 #-stdlib=libc++

LD	 = $(CXX)
LDFLAGS  = $(CXXFLAGS)

LIBS	 = -lmpfr -lgmp

all: horner-sine.x tgamma.x basic.x theveny.x # bug.x

%.x: %.o
	$(LD) $(LDFLAGS) $< $(LIBS) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f *.o
	-rm -f *.x
	-rm -rf *x.dSYM
