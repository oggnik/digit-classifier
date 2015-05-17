CFLAGS = -g
export CFLAGS

OBJ_FILES = main.o Reader.o Image.o NeuralNetwork.o Neuron.o HiddenNeuron.o InputNeuron.o OutputNeuron.o

.PHONY: $(OBJ_FILES)

all: $(OBJ_FILES)
	g++ $(CFLAGS) -o classifier $(OBJ_FILES)

Image.o:
	$(MAKE) -C data Image.o
	cp data/Image.o .

Reader.o:
	$(MAKE) -C reader Reader.o
	cp reader/Reader.o .

main.o:
	$(MAKE) -C main main.o
	cp main/main.o .

NeuralNetwork.o:
	$(MAKE) -C nn NeuralNetwork.o
	cp nn/NeuralNetwork.o .

Neuron.o:
	$(MAKE) -C nn Neuron.o
	cp nn/Neuron.o .

HiddenNeuron.o:
	$(MAKE) -C nn HiddenNeuron.o
	cp nn/HiddenNeuron.o .

InputNeuron.o:
	$(MAKE) -C nn InputNeuron.o
	cp nn/InputNeuron.o .

OutputNeuron.o:
	$(MAKE) -C nn OutputNeuron.o
	cp nn/OutputNeuron.o .

clean:
	-rm -rf *.o
	-rm classifier