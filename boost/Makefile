CXX 	 = g++
CXXFLAGS = -g -Wall

LD	 = $(CXX)
LDFLAGS  = $(CXXFLAGS)

LIBS	 = -lmpfr -lgmp -lquadmath -lm

all: horner-sine.x tgamma.x basic.x theveny.x # bug.x

%.x: %.o
	$(LD) $(LDFLAGS) $< $(LIBS) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f *.o
	-rm -f *.x
	-rm -rf *x.dSYM
