CFLAGS = 

all: reader.o

reader.o:
	-$(MAKE) -C reader reader.o
	-cp reader/reader.o .

clean:
	-rm -rf *.o
	-rm reader.o
	-$(MAKE) -C reader clean