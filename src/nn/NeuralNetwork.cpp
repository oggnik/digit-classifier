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

	// Set the hidden layer neurons
	// These have dummy neurons again
	for (int i = 0; i < num_hidden_layers; i++) {
		// i + 1 because we want to skip the input layer
		network[i + 1].resize(num_hidden_neurons + 1);
	}

	// Set the number of output neurons.
	// Note that for this there is no dummy neuron because we don't need them for the output layer
	network[num_hidden_layers + 1].resize(num_output_neurons);

	



	// Set up the interconnections in the network

	// Input layer
	for (int i = 0; i < num_input_neurons; i++) {
		network[0][i] = new InputNeuron;
	}
	network[0][num_input_neurons] = new DummyNeuron;

	// Hidden layers
	for (int i = 0; i < num_hidden_layers; i++) {
		for (int j = 0; j < num_hidden_neurons; j++) {
			// i + 1 because we want to skip the input layer
			network[i+1][j] = new HiddenNeuron;

			network[i+1][j]->setPreviousLayer(network[i]);
		}
		network[i+1][num_hidden_neurons] = new DummyNeuron;
	}

	// Output layer
	for (int i = 0; i < num_output_neurons; i++) {
		// num_hidden_layers + 1 is the index of the output layer
		network[num_hidden_layers + 1][i] = new OutputNeuron;

		network[num_hidden_layers + 1][i]->setPreviousLayer(network[num_hidden_layers]);
	}
	// The output layer doesn't need a dummy neuron


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
	cout << "Hidden layers:" << endl;
	for (int i = 1; i < network.size() - 1; i++) {
		cout << "\tLayer size: " << network[i].size() << endl;
	}
	cout << "Output layer size: " << network[network.size() - 1].size() << endl;
}