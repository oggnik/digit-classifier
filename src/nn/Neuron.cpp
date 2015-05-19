#include "Neuron.h"
#include <iostream>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine rand_generator(seed);
std::uniform_real_distribution<double> rand_dist(-1.0, 1.0);

Neuron::Neuron() {
	for (int i = 0; i < weights.size(); i++) {
		weights[i] = rand_dist(rand_generator);
	}
	value = 0.0;
	index = 0;
	backPropDelta = 0.0;
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
 * Get a specific weight
 */
double Neuron::getWeightByIndex(int index) {
	return weights[index];
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

/**
 * Set the neuron's next layer
 */
void Neuron::setNextLayer(std::vector <Neuron *> next_layer) {
	this->next_layer = next_layer;
}

/**
 * Set the index of the neuron within its layer
 */
void Neuron::setIndex(int index) {
	this->index = index;
}

/**
 * Get the back propogation delta for this neuron
 */
double Neuron::getBackPropDelta() {
	return backPropDelta;
}

double Neuron::calculateBackPropDelta() {
	// Calculate the delta value
	double derivativeIn = derivativeInputValue();

	double deltaSum = 0;
	for (int j = 0; j < next_layer.size(); j++) {
		double weightVal = next_layer[j]->getWeightByIndex(index);
		double deltaVal = next_layer[j]->getBackPropDelta();
		deltaSum += weightVal * deltaVal;
	}

	return deltaSum * derivativeIn;
}

void Neuron::updateWeights() {
		// Update the weights
	for (int i = 0; i < weights.size(); i++) {

		double diff = LEARNING_RATE * backPropDelta * previous_layer[i]->getValue();
		//cout << diff << endl;

		weights[i] = weights[i] + diff;
	}
}

/**
 * Calculate the new weights via backpropogation
 */
void Neuron::calculateWeights() {
	/*
		W(i, j) = W(i, j) + alpha * val(i) * delta(j)
		delta(j) = g'(in(j)) * sum(W(j, k) * delta(k))
	*/


	backPropDelta = calculateBackPropDelta();

	updateWeights();
}

/**
 * This calculates g'(in)
 */
double Neuron::derivativeInputValue() {
	double sum = 0.0;

	// Add up inputs * weights
	int previous_layer_size = previous_layer.size();
	for (int i = 0; i < previous_layer_size; i++) {
		sum += weights[i] * previous_layer[i]->getValue();
	}
	// Apply the derivative of the sigmoid function
	// e^x / (1 + e^x)^2

	double denominator = 1 + exp(sum);
	// Square it
	denominator *= denominator;

	double numerator = exp(sum);

	return numerator / denominator;
}