#include <vector>
#include <random>
#include <chrono>
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
		 * The learning rate for training
		 */
		static constexpr double LEARNING_RATE = 0.1;

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
		 * Get a specific weight
		 */
		virtual double getWeightByIndex(int index);

		/**
		 * Set the neuron's previous layer
		 * This clears any weights the neuron may have had
		 */
		void setPreviousLayer(std::vector <Neuron *> previous_layer);

		/**
		 * Set the neuron's next layer
		 */
		void setNextLayer(std::vector <Neuron *> next_layer);

		/**
		 * Set the index of the neuron within its layer
		 */
		void setIndex(int index);

		/**
		 * Get the back propogation delta for this neuron
		 */
		double getBackPropDelta();

		/**
		 * Calculate the new weights via backpropogation
		 */
		virtual void calculateWeights();

	protected:
		std::vector <double>weights;
		double value;
		std::vector <Neuron *> previous_layer;
		std::vector<Neuron *> next_layer;
		int index;

		double backPropDelta;

		/**
		 * This calculates g'(in)
		 */
		double derivativeInputValue();
};



#define neuron_header
#endif