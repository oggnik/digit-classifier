#include <vector>
#include <math.h>
#include "Neuron.h"

#ifndef output_neuron_header

class OutputNeuron : public Neuron {
	public:
		/**
		 * Constructor
		 */
		OutputNeuron();
		/**
		 * Set the error of the neuron for training
		 */
		void setNeuronError(double error);
		/**
		 * A modified calculation of weights based on the error
		 */
		void calculateWeights();

	private:
		double error(0);
};

#define output_neuron_header
#endif