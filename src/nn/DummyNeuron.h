#include <vector>
#include <math.h>
#include "Neuron.h"

#ifndef dummy_neuron_header

/**
 * A DummyNeuron always returns a value of -1
 * This is used to act as a threshold for other neurons
 */
class DummyNeuron : public Neuron {
	public:
		/**
		 * This method does nothing
		 */
		void computeValue();
		/**
		 * This method always returns -1
		 */
		double getValue();

		/**
		 * This method does nothing
		 */
		void calculateWeights();
};

#define dummy_neuron_header
#endif