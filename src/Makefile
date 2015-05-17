CFLAGS = 
export CFLAGS

.PHONY: main.o Reader.o Image.o

all: Reader.o Image.o main.o
	g++ $(CFLAGS) -o classifier main.o Reader.o Image.o

Image.o:
	$(MAKE) -C data Image.o
	cp data/Image.o .

Reader.o:
	$(MAKE) -C reader Reader.o
	cp reader/Reader.o .

main.o:
	$(MAKE) -C main main.o
	cp main/main.o .

nn.o:
	$(MAKE) -C nn nn.o
	cp nn/nn.o .

clean:
	-rm -rf *.o
	-rm Reader.o
	-rm classifier