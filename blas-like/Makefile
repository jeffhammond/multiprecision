COMPILER := INTEL

ifeq ($(COMPILER),INTEL)
OFLAGS = -g -O3 -xHost -qopenmp

FC = ifort
CC = icc

CFLAGS = $(OFLAGS) -std=gnu99
F90FLAGS = $(OFLAGS)
F77FLAGS = $(OFLAGS)

LIBS =
endif

ifeq ($(COMPILER),GCC)
OFLAGS = -g -O3 -fopenmp

FC = gfortran-4.9
CC = gcc-4.9

CFLAGS = $(OFLAGS) -std=gnu99
F90FLAGS = $(OFLAGS)
F77FLAGS = $(OFLAGS)

LIBS = -lquadmath
endif

TESTS = testquad.x testdotf.x
IMPLS = dot.o dot77.o dotc.o

all: $(TESTS)

%.a: $(IMPLS)
	$(AR) -r $@ $(IMPLS)

%.o: %.f90
	$(FC) $(F90FLAGS) -c $<

%.o: %.f
	$(FC) $(F77FLAGS) -c $<

%.o: %.c quad.h
	$(CC) $(CFLAGS) -c $< 

%.x: %.f90 libdot.a
	$(FC) $(F90FLAGS) $< -L. -ldot $(LIBS) -o $@

%.x: %.f libdot.a
	$(FC) $(F77FLAGS) $< -L. -ldot $(LIBS) -o $@

%.x: %.c libdot.a
	$(CC) $(CFLAGS)   $< -L. -ldot $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TESTS)
	-rm -f *.dwarf
	-rm -fr *.dSYM

