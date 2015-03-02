COMPILER := INTEL

ifeq ($(COMPILER),INTEL)
OFLAGS = -g -O3 -xHost

FC = ifort
CC = icc

CFLAGS = $(OFLAGS) -std=gnu99
F90FLAGS = $(OFLAGS)
F77FLAGS = $(OFLAGS)

LIBS = 
endif

ifeq ($(COMPILER),GCC)
OFLAGS = -g -O3

FC = gfortran-4.9
CC = gcc-4.9

CFLAGS = $(OFLAGS) -std=gnu99
F90FLAGS = $(OFLAGS)
F77FLAGS = $(OFLAGS)

LIBS = -lquadmath
endif

TESTS = testquad.x
IMPLS = dot.o dot77.o dotc.o

all: $(TESTS) $(IMPLS)

%.o: %.f90
	$(FC) $(F90FLAGS) -c $<

%.o: %.f
	$(FC) $(F77FLAGS) -c $<

%.o: %.c quad.h
	$(CC) $(CFLAGS) -c $< 

%.x: %.c
	$(CC) $(CFLAGS) $< $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TESTS)
	-rm -f *.dwarf
	-rm -fr *.dSYM

