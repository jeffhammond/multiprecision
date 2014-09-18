CC 	   = clang
CFLAGS = -g -Wall -std=c99
LIBS= -lm

TESTS = convert

all:  $(TESTS)

%: %.c
	$(CC) $(CCFLAGS) $< -o $@

clean:
	-rm -f *.o
	-rm -f $(TESTS)
	-rm -rf *.dSYM

