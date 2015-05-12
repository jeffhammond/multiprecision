COMPILER := INTEL

ifeq ($(COMPILER),INTEL)
OFLAGS = -g -O3 -xHost -mavx -qopenmp

FC = ifort
CC = icc

CFLAGS = $(OFLAGS) -std=gnu99
F90FLAGS = $(OFLAGS) -heap-arrays
F77FLAGS = $(OFLAGS) -heap-arrays

LIBS =
endif

ifeq ($(COMPILER),GCC)
OFLAGS = -g -O3 -fopenmp

FC = gfortran-4.9
CC = gcc-4.9

CFLAGS = $(OFLAGS) -std=gnu99
F90FLAGS = $(OFLAGS)
F77FLAGS = $(OFLAGS)

LIBS = -lm -lquadmath
endif

TESTS = test.x
IMPLS = matmul.o

all: $(TESTS)

%.s: %.f90
	$(FC) $(F90FLAGS) -S $<

%.o: %.f90
	$(FC) $(F90FLAGS) -c $<

%.x: %.f90 matmul.o
	$(FC) $(F90FLAGS) $< matmul.o $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f *.s
	-rm -f $(TESTS)
	-rm -f *.dwarf
	-rm -fr *.dSYM

