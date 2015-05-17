#include <vector>
#include <math.h>
#include <iostream>
#include "Neuron.h"
#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"

#ifndef neural_network_header

class NeuralNetwork {
	public:
		/**
		 * Constructor
		 */
		NeuralNetwork(int num_input_neurons, int num_hidden_neurons, int num_hidden_layers, int num_output_neurons);

		/**
		 * Deconstructor
		 */
		~NeuralNetwork();

		/**
		 * Compute the output of the network with the given inputs
		 */
		std::vector <double> computeOutput(std::vector <double> inputs);

		/**
		 * Print the neural network layout
		 */
		void print();

	private:
		std::vector <std::vector <Neuron *> > network;
};

#define neural_network_header
#endif