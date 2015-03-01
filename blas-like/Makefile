OFLAGS = -g -O3 -xHost

FC = ifort
CC = icc

CFLAGS = $(OFLAGS) -std=gnu99
F90FLAGS = $(OFLAGS)
F77FLAGS = $(OFLAGS)

TESTS = 
IMPLS = dot.o dot77.o dotc.o

all: $(TESTS) $(IMPLS)

%.o: %.f90
	$(FC) $(F90FLAGS) -c $<

%.o: %.f
	$(FC) $(F77FLAGS) -c $<

%.o: %.c quad.h
	$(CC) $(CFLAGS) -c $< 

clean:
	-rm -f *.o
	-rm -f $(TESTS)
