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
}

/**
 * Deconstructor
 */
NeuralNetwork::~NeuralNetwork() {

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