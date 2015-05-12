COMPILER := INTEL

ifeq ($(COMPILER),INTEL)
OFLAGS = -g -O3 -xHost -mavx -qopenmp

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

LIBS = -lm -lquadmath
endif

TESTS = testquad.x testdotf.x testdotc.x testcopyc.x testscalc.x testpowc.x
IMPLS = dot.o dot77.o dotc.o

all: $(TESTS)

%.a: $(IMPLS)
	$(AR) -r $@ $(IMPLS)

%.s: %.f90
	$(FC) $(F90FLAGS) -S $<

%.s: %.f
	$(FC) $(F77FLAGS) -S $<

%.s: %.c quad.h dotc.h
	$(CC) $(CFLAGS) -S $< 

%.o: %.f90
	$(FC) $(F90FLAGS) -c $<

%.o: %.f
	$(FC) $(F77FLAGS) -c $<

%.o: %.c quad.h dotc.h
	$(CC) $(CFLAGS) -c $< 

%.x: %.f90 libdot.a
	$(FC) $(F90FLAGS) $< -L. -ldot $(LIBS) -o $@

%.x: %.f libdot.a
	$(FC) $(F77FLAGS) $< -L. -ldot $(LIBS) -o $@

%.x: %.c libdot.a
	$(CC) $(CFLAGS)   $< -L. -ldot $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f *.s
	-rm -f $(TESTS)
	-rm -f *.dwarf
	-rm -fr *.dSYM

