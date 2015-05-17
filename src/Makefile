CFLAGS = 
export CFLAGS

.PHONY: reader.o image.o

all: reader.o image.o
	g++ $(CFLAGS) -o classifier reader.o image.o

image.o:
	$(MAKE) -C data image.o
	cp data/image.o .

reader.o:
	$(MAKE) -C reader reader.o
	cp reader/reader.o .

clean:
	-rm -rf *.o
	-rm reader.o
	-$(MAKE) -C reader clean