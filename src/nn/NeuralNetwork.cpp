#include "NeuralNetwork.h"

using namespace std;

/**
 * Constructor
 */
NeuralNetwork::NeuralNetwork(int num_input_neurons, int num_hidden_neurons, int num_hidden_layers, int num_output_neurons) {
	// Set the number of layers, num hidden + input + output
	network.resize(num_hidden_layers + 2);

	// Set the number of input neurons, 1 extra for the dummy neuron
	network[0].resize(num_input_neurons + 1);

	// Set the number of output neurons.
	// Note that for this there is no dummy neuron because we don't need them for the output layer
	network[num_hidden_layers + 1].resize(num_output_neurons);

	// Set the hidden layer neurons
	// These have dummy neurons again
	for (int i = 0; i < num_hidden_layers; i++) {
		// i + 1 because we want to skip the input layer
		network[i + 1].resize(num_hidden_neurons + 1);
	}

	// Set up the interconnections in the network
	for (int i = 0; i < num_input_neurons; i++) {
		network[0][i] = new InputNeuron;
	}
	network[0][num_input_neurons] = new DummyNeuron;

	for (int i = 0; i < num_hidden_layers; i++) {
		for (int j = 0; j < num_hidden_neurons; j++) {
			network[i][j] = new HiddenNeuron;
		}
		network[i][num_hidden_neurons] = new DummyNeuron;
	}

	for (int i = 0; i < num_output_neurons; i++) {
		network[num_hidden_layers + 1][i] = new OutputNeuron;
	}
	network[num_hidden_layers + 1][num_output_neurons] = new DummyNeuron;
}

/**
 * Deconstructor
 */
NeuralNetwork::~NeuralNetwork() {
	for (int i = 0; i < network.size(); i++) {
		for (int j = 0; j < network[i].size(); j++) {
			delete network[i][j];
		}
	}
}

/**
 * Compute the output of the network with the given inputs
 */
std::vector <double> computeOutput(std::vector <double> inputs);

/**
 * Print the neural network layout
 */
void NeuralNetwork::print() {
	cout << "Neural Network:" << endl;
	cout << "Input layer size: " << network[0].size() << endl;
}