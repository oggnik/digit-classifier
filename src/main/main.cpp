#include "../data/Image.h"
#include "../reader/Reader.h"
#include "../nn/NeuralNetwork.h"
#include "vector"

using namespace std;

double getErrorRate(NeuralNetwork *network, vector<Image *> image_set);

int main(int argc, char **argv) {

	cout << "Loading training set" << endl;

	string training_image_file = "../data/train-images-idx3-ubyte";
	string training_label_file = "../data/train-labels-idx1-ubyte";

	vector <Image *> training_images = read_dataset(training_image_file, training_label_file);

	cout << "Training neural network" << endl;

	NeuralNetwork *network = new NeuralNetwork(784, 10, 3, 10);
	network->print();

	Image *testImage = training_images[0];
	testImage->print();
	vector <double> output = network->computeOutput(testImage->getImageAsScaledVector());

	cout << "Network output" << endl;
	for (int i = 0; i < output.size(); i++) {
		cout << "\t" << i << ": " << output[i] << endl;
	}

	vector <double> expectedOutput(10);
	expectedOutput[5] = 1.0;
	network->trainNetwork(expectedOutput, testImage->getImageAsScaledVector());

	output = network->computeOutput(testImage->getImageAsScaledVector());
	cout << "Network output" << endl;
	for (int i = 0; i < output.size(); i++) {
		cout << "\t" << i << ": " << output[i] << endl;
	}

	//cout << "Initial error rate: " << getErrorRate(network, training_images) << endl;


	// Free memory

	for (int i = 0; i < training_images.size(); i++) {
		delete training_images[i];
	}

	delete network;

	return 0;
}


/**
 * Get the error rate of the network for a given image set
 */
double getErrorRate(NeuralNetwork *network, vector <Image *> image_set) {
	int numImages = image_set.size();
	int numErrors = 0;

	for (int i = 0; i < numImages; i++) {
		// Get the outputs
		vector <double> imageOutput = network->computeOutput(image_set[i]->getImageAsScaledVector());
		// Find the maximum, this is the networks vote
		int maxIndex = 0;
		for (int j = 0; j < imageOutput.size(); j++) {
			if (imageOutput[j] > imageOutput[maxIndex]) {
				maxIndex = j;
			}
		}

		if (maxIndex != image_set[i]->getLabel()) {
			numErrors++;
		}
	}
	return (1.0 * numErrors) / numImages;
}