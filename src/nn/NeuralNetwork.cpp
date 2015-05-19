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
		network[0][i]->setIndex(i);
	}
	network[0][num_input_neurons] = new DummyNeuron;

	// Hidden layers
	for (int i = 0; i < num_hidden_layers; i++) {
		for (int j = 0; j < num_hidden_neurons; j++) {
			// i + 1 because we want to skip the input layer
			network[i+1][j] = new HiddenNeuron;

			network[i+1][j]->setPreviousLayer(network[i]);
			network[i+1][j]->setIndex(j);
		}
		network[i+1][num_hidden_neurons] = new DummyNeuron;

		// Set the previous layer's next layer
		for (int j = 0; j < network[i].size(); j++) {
			network[i][j]->setNextLayer(network[i+1]);
		}
	}

	// Output layer
	for (int i = 0; i < num_output_neurons; i++) {
		// num_hidden_layers + 1 is the index of the output layer
		network[num_hidden_layers + 1][i] = new OutputNeuron;

		network[num_hidden_layers + 1][i]->setPreviousLayer(network[num_hidden_layers]);

		network[num_hidden_layers + 1][i]->setIndex(i);
	}
	// The output layer doesn't need a dummy neuron

	// Set the previous layer's next layer
	for (int i = 0; i < num_output_neurons; i++) {
		network[num_hidden_layers][i]->setNextLayer(network[num_hidden_layers + 1]);
	}

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
vector <double> NeuralNetwork::computeOutput(vector <double> inputs) {
	vector <double> outputs(network[network.size() - 1].size());

	// Set the input values
	for (int i = 0; i < inputs.size(); i++) {
		InputNeuron *neuron = dynamic_cast<InputNeuron *>(network[0][i]);
		neuron->setInputValue(inputs[i]);
	}

	// Compute the values for all the neurons
	for (int i = 1; i < network.size(); i++) {
		for (int j = 0; j < network[i].size(); j++) {
			network[i][j]->computeValue();
		}
	}

	// Get the output layers values
	for (int i = 0; i < network[network.size() - 1].size(); i++) {
		outputs[i] = network[network.size() - 1][i]->getValue();
	}

	return outputs;
}


/**
 * Perform a single round of training on the network
 */
void NeuralNetwork::trainNetwork(vector <double> expectedOutput, vector <double> inputs) {
	vector<double> outputs = computeOutput(inputs);

	for (int i = 0; i < expectedOutput.size(); i++) {
		// Set the error
		double error = expectedOutput[i] - outputs[i];
		OutputNeuron *outputNeuron = dynamic_cast<OutputNeuron *>(network[network.size() - 1][i]);
		outputNeuron->setNeuronError(error);

		for (int j = network.size() - 1; j >= 0; j--) {
			for (int k = 0; k < network[j].size(); k++) {
				network[j][k]->calculateWeights();
			}
		}
	}
}


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