#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Neuron.h"
#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"
#include "DummyNeuron.h"

#ifndef neural_network_header

class NeuralNetwork {
	public:
		/**
		 * Constructor with parameters
		 */
		NeuralNetwork(int num_input_neurons, int num_hidden_neurons, int num_hidden_layers, int num_output_neurons);

		/**
		 * Constructor from a save
		 */
		NeuralNetwork(std::string file_name);

		/**
		 * Deconstructor
		 */
		~NeuralNetwork();

		/**
		 * Compute the output of the network with the given inputs
		 */
		std::vector <double> computeOutput(std::vector <double> inputs);

		/**
		 * Perform a single round of training on the network
		 */
		void trainNetwork(std::vector<double> expectedOutput, std::vector <double> inputs);

		/**
		 * Save the state of the network to the specified file
		 */
		void saveToFile(std::string file_name);

		/**
		 * Print the neural network layout
		 */
		void print();

	private:
		std::vector <std::vector <Neuron *> > network;

		/**
		 * Initialize the neural network
		 */
		void init(int num_input_neurons, int num_hidden_neurons, int num_hidden_layers, int num_output_neurons);
};

#define neural_network_header
#endif