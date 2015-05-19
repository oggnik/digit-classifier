#include <vector>
#include <random>
#include <math.h>

#ifndef neuron_header

class Neuron {
	public:

		/**
		 * Constructor
		 * Initialize the weights to random values between -1 and 1
		 */
		Neuron();

		/**
		 * Make the neuron compute its value
		 */
		virtual void computeValue();

		/**
		 * Get the neuron's value
		 * This does not update automatically, computeValue must be called to refresh the value
		 */
		double getValue();

		/**
		 * Set the weights of the neuron
		 * This replaces the current weights of the neuron
		 */
		void setWeights(std::vector <double> weights);

		/**
		 * Get the neuron's current weights
		 */
		std::vector <double> getWeights();

		/**
		 * Set the neuron's previous layer
		 * This clears any weights the neuron may have had
		 */
		void setPreviousLayer(std::vector <Neuron *> previous_layer);

	protected:
		std::vector <double>weights;
		double value;
		std::vector <Neuron *> previous_layer;
};



#define neuron_header
#endif