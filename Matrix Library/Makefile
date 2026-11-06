CC = gcc
AR = ar

CFLAGS = -Wall -Wextra
PREFIX = /usr/local

all: libmatrix.a

matrix_lib.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c -o matrix_lib.o

libmatrix.a: matrix_lib.o
	$(AR) rcs libmatrix.a matrix_lib.o

install: all
	install -d $(DESTDIR)$(PREFIX)/include
	install -d $(DESTDIR)$(PREFIX)/lib
	install -m 644 matrix.h $(DESTDIR)$(PREFIX)/include/
	install -m 644 libmatrix.a $(DESTDIR)$(PREFIX)/lib/

clean:
	rm -f matrix_lib.o libmatrix.a

.PHONY: all install clean