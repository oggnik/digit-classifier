#include "Neuron.h"

/**
 * Make the neuron compute its value
 */
void Neuron::computeValue() {
	double value = 0.0;

	// Add up inputs * weights
	int previous_layer_size = weights.size();
	for (int i = 0; i < previous_layer_size; i++) {
		value += weights[i] * (*previous_layer)[i].getValue();
	}

	// Apply the sigmoid function
	double denominator = 1 + exp(-1.0 * value);
	value = 1.0 / denominator;

	this->value = value;
}

/**
 * Get the neuron's value
 * This does not update automatically, computeValue must be called to refresh the value
 */
double Neuron::getValue() {
	return value;
}

/**
 * Set the weights of the neuron
 * This replaces the current weights of the neuron
 */
void Neuron::setWeights(std::vector <double> weights) {
	this->weights = weights;
}

/**
 * Get the neuron's current weights
 */
std::vector <double> Neuron::getWeights() {
	return weights;
}

/**
 * Set the neuron's previous layer
 */
void Neuron::setPreviousLayer(std::vector <Neuron> *previous_layer) {
	this->previous_layer = previous_layer;
}