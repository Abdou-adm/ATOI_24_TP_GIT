CC = gcc
CFLAGS = -O3 -g
LDFLAGS = -L. -lppm

BINARIES = test mandel
LIBRARIES = libppm.so
TARGET = $(BINARIES) $(LIBRARIES)

all: $(TARGET)

libppm.so: ppm.c
	$(CC) $(CFLAGS) -fpic -shared $^ -o $@

test: main.c libppm.so
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) -lm

mandel: mandel.c libppm.so
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) -lm

clean:
	rm -f $(BINARIES) $(LIBRARIES)
