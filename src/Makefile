CFLAGS = 
export CFLAGS

.PHONY: main.o reader.o image.o

all: reader.o image.o main.o
	g++ $(CFLAGS) -o classifier main.o reader.o image.o

image.o:
	$(MAKE) -C data image.o
	cp data/image.o .

reader.o:
	$(MAKE) -C reader reader.o
	cp reader/reader.o .

main.o:
	$(MAKE) -C main main.o
	cp main/main.o .

clean:
	-rm -rf *.o
	-rm reader.o
	-$(MAKE) -C reader clean