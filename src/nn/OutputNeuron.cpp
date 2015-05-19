#include "OutputNeuron.h"

/*
 * Set the error of the neuron for training
 */
void OutputNeuron::setNeuronError(double error) {
	this->error = error;
}

/*
 * A modified calculation of weights based on the error
 */
void OutputNeuron::calculateWeights() {
	/*
		W(i, j) = W(i, j) + alpha * val(i) * delta(j)
		delta(j) = g'(in(j)) * sum(W(j, k) * delta(k))
	*/

	// Calculate the delta value
	double derivativeIn = derivativeInputValue();

	backPropDelta = error * derivativeIn;


	// Update the weights
	for (int i = 0; i < weights.size(); i++) {
		double weight = weights[i];

		double diff = LEARNING_RATE * backPropDelta * previous_layer[i]->getValue();

		weight += diff;

		weights[i] = weight;
	}
}