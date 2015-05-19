#include <vector>
#include <math.h>
#include "Neuron.h"

#ifndef input_neuron_header

class InputNeuron : public Neuron {
	public:
		/**
		 * Set the input value for the neuron
		 */
		void setInputValue(double value);
		/**
		 * This method does nothing
		 */
		void computeValue();

		/**
		 * This method does nothing
		 */
		void calculateWeights();
};

#define input_neuron_header
#endif