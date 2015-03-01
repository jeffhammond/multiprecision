OFLAGS = -g -O3 -xHost

FC = ifort
CC = icc

CFLAGS = $(OFLAGS) -std=c99
FFLAGS = $(OFLAGS) -stand f03

TESTS = 
IMPLS = dot.o

all: $(TESTS) $(IMPLS)

%.o: %.f90
	$(FC) $(FFLAGS) -c $<

%.o: %.f
	$(FC) $(FFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

clean:
	-rm -f *.o
	-rm -f $(TESTS)
