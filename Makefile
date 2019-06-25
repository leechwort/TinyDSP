src = $(wildcard src/*.c)
kissfft_obj = $(wildcard ext/kissfft/*.o)

LDFLAGS = -lm -Iext/kissfft/ -Itests/ -I./

# list the libfoo rule as a dependency
all: \
	tests_x86
tinydsp.o: libkissfft
	gcc -Wall -fPIC -c *.c $(LDFLAGS)
tests_x86: tests/test_x86.c tests/testfuncs.c tinydsp.o
	gcc -Wall -fPIC -o $@ tests/testfuncs.c \
		tests/test_x86.c \
		tinydsp.o  $(kissfft_obj) $(LDFLAGS)

.PHONY: clean
clean:
	rm tests_x86
	rm tinydsp.o
	rm -f $(kissfft_obj)

.PHONY: libkissfft
libkissfft:
	$(MAKE) -C ext/kissfft
