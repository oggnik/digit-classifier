#include "Neuron.h"
#include <iostream>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine rand_generator(seed);
std::uniform_real_distribution<double> rand_dist(-1.0, 1.0);

Neuron::Neuron() {
	for (int i = 0; i < weights.size(); i++) {
		weights[i] = rand_dist(rand_generator);
		cout << weights[i] << endl;
	}
	value = 0.0;
}

/**
 * Make the neuron compute its value
 */
void Neuron::computeValue() {
	double value = 0.0;

	// Add up inputs * weights
	int previous_layer_size = weights.size();
	for (int i = 0; i < previous_layer_size; i++) {
		value += weights[i] * previous_layer[i]->getValue();
	}

	// Apply the sigmoid function
	double denominator = 1 + exp(value * -1.0);
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
 * This clears any weights the neuron may have had
 */
void Neuron::setPreviousLayer(std::vector <Neuron *> previous_layer) {
	this->previous_layer = previous_layer;

	// Reset the weights
	weights.resize(previous_layer.size());
	for (int i = 0; i < weights.size(); i++) {
		weights[i] = rand_dist(rand_generator);
	}
}