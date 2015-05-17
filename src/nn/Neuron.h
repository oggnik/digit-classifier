#include <string>
#include <iostream>
#include <cstdint>
#include <vector>

#ifndef neuron_header

class Neuron {
	public:
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
		 */
		void setPreviousLayer(std::vector <Neuron> previous_layer);

	protected:
		double *weights;
		double value;
		std::vector <Neuron> previous_layer;
};

#define neuron_header
#endif