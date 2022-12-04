TARGET  := png16.library
VERSION := 53

CC     := ppc-amigaos-gcc
STRIP  := ppc-amigaos-strip
AR     = ppc-amigaos-ar
RANLIB = ppc-amigaos-ranlib

BUILDSYS = $(shell uname -s)

# Only use host argument if cross-compiling
ifneq ($(BUILDSYS),AmigaOS)
	HOSTARG = --host=ppc-amigaos
else
	HOSTARG = 
endif

PNG16DIR = libpng-1.6.38

OPTIMIZE = -O2 -fomit-frame-pointer
DEBUG    = -g
INCLUDES = -I./include -I./$(PNG16DIR) -I./png16-build
DEFINES  = -D_COMPILING_PNG16LIB
WARNINGS = -Wall -Wwrite-strings -Werror

CFLAGS   = $(OPTIMIZE) $(DEBUG) $(INCLUDES) $(DEFINES) $(WARNINGS)
LDFLAGS  = -static
LIBS     = png16-build/.libs/libpng16.a

STRIPFLAGS = -R.comment --strip-unneeded-rel-relocs

main_SRCS = main/Obtain.c main/Release.c
main_OBJS = $(main_SRCS:.c=.o)

SRCS = init.c zlib/stubs.c $(main_SRCS)
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: $(TARGET) libpng16.a pngcrush

init.o: $(TARGET)_rev.h png16_vectors.c png16_vectors.h

$(main_OBJS): png16_vectors.h

png16-build/Makefile: $(PNG16DIR)/configure
	mkdir -p png16-build
	rm -rf png16-build/*
	cd png16-build && ../$(PNG16DIR)/configure --prefix=/SDK/local/newlib $(HOSTARG) --disable-shared

.PHONY: build-png16
build-png16: png16-build/Makefile
	$(MAKE) -C png16-build

$(TARGET): build-png16 $(OBJS)
	$(CC) $(LDFLAGS) -nostartfiles -o $@.debug $(OBJS) $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

libpng16.a: static/autoinit_png16_base.o static/autoinit_png16_main.o static/stubs.o
	$(AR) -crv $@ $^
	$(RANLIB) $@

pngcrush: pngcrush-1.8.13/pngcrush.o zlib/stubs.o zlib/autoinit_z_base.o zlib/autoinit_z_main.o libpng16.a
	$(CC) $(LDFLAGS) -o $@.debug $^
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

.PHONY: clean
clean:
	rm -f pngcrush pngcrush.debug pngcrush-1.8.13/*.o zlib/*.o
	rm -f $(TARGET) $(TARGET).debug *.o main/*.o lib*.a static/*.o
	rm -rf png16-build

.PHONY: revision
revision:
	bumprev $(VERSION) $(TARGET)

