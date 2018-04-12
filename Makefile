.DEFAULT_GOAL := default

IDIR = src/
CC = g++
CFLAGS=-I$(IDIR)

ODIR=obj
LIBS=-lgd

_DEPS = main.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build_dirs:
	echo "1"
	mkdir -p obj/

v4c-video-slider: $(OBJ)
	echo "2"
	$(CC) -o v4c-video-slider $< $(CFLAGS) $(LIBS)

default: build_dirs v4c-video-slider

clean:
	rm -rf $(ODIR)
	rm -f v4c-video-slider