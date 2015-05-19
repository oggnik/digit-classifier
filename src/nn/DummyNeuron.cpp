#include "DummyNeuron.h"

/**
 * This method does nothing
 */
void DummyNeuron::computeValue() {
	// Do nothing
}
/**
 * This method always returns -1
 */
double DummyNeuron::getValue() {
	return -1;
}

/**
 * Get a specific weight
 */
double DummyNeuron::getWeightByIndex(int index) {
	return 0;
}

/**
 * This method does nothing
 */
void DummyNeuron::calculateWeights() {
	// Do nothing
}