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
	vector <double> output = network->computeOutput(testImage->getImageAsVector());

	cout << "Network output" << endl;
	for (int i = 0; i < output.size(); i++) {
		cout << "\t" << i << ": " << output[i] << endl;
	}



	for (int i = 0; i < training_images.size(); i++) {
		free(training_images[i]);
	}

	delete network;

	return 0;
}


/**
 * Get the error rate of the network for a given image set
 */
double getErrorRate(NeuralNetwork *network, vector <Image *> image_set) {
	int numImages = image_set.size();

	for (int i = 0; i < numImages; i++) {

	}
	return 0.0;
}