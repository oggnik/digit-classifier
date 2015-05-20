#include "../data/Image.h"
#include "../reader/Reader.h"
#include "../nn/NeuralNetwork.h"
#include <vector>
#include <string.h>

using namespace std;

double getErrorRate(NeuralNetwork *network, vector<Image *> image_set);
NeuralNetwork *train(vector <Image *> training_images);


string training_image_file = "../data/train-images-idx3-ubyte";
string training_label_file = "../data/train-labels-idx1-ubyte";

string test_image_file = "../data/t10k-images-idx3-ubyte";
string test_label_file = "../data/t10k-labels-idx1-ubyte";

int main(int argc, char **argv) {

	bool load = false;
	string load_file = "";

	if (argc == 3 && strcmp(argv[1], "-f") == 0) {
		load = true;
		load_file = argv[2];
	}

	NeuralNetwork *network;

	cout << "Loading training set" << endl;
	vector <Image *> training_images = read_dataset(training_image_file, training_label_file);

	if (!load) {
		// Train
		cout << "Training neural network" << endl;
		network = train(training_images);
	} else {
		// Load
		cout << "Loading neural network from file" << endl;
		network = new NeuralNetwork(load_file);
	}

	double training_error_rate = getErrorRate(network, training_images);
	cout << "Final error rate on training data: " << training_error_rate << endl;

	// Image *testImage = training_images[0];
	// testImage->print();
	// vector <double> output = network->computeOutput(testImage->getImageAsScaledVector());

	// cout << "Network output" << endl;
	// for (int i = 0; i < output.size(); i++) {
	// 	cout << "\t" << i << ": " << output[i] << endl;
	// }

	// Test against the test data
	vector <Image *> test_images = read_dataset(test_image_file, test_label_file);
	double test_error_rate = getErrorRate(network, test_images);
	cout << "Final error rate on test data: " << test_error_rate << endl;

	// Free memory
	for (int i = 0; i < training_images.size(); i++) {
		delete training_images[i];
	}

	delete network;

	return 0;
}

NeuralNetwork *train(vector <Image *> training_images) {
	NeuralNetwork *network = new NeuralNetwork(784, 200, 1, 10);

	double error_rate = getErrorRate(network, training_images);
	cout << "Initial error rate: " << error_rate << endl;

	cout << "Training..." << endl;
	int iterations = 0;
	while (error_rate > 0.2) {
		cout << "Training iteration: " << iterations << ", Error rate: " << error_rate << endl;
		// Perform a round of training
		for (int i = 0; i < training_images.size(); i++) {
			if (i % 1000 == 0) {
				cout << (i * 1.0 / training_images.size()) << endl;
			}
			// Set expected outputs
			vector <double> expectedOutput(10);
			Image *image = training_images[i];
			expectedOutput[image->getLabel()] = 1.0;
			// train
			network->trainNetwork(expectedOutput, image->getImageAsScaledVector());
		}
		error_rate = getErrorRate(network, training_images);
		network->saveToFile("testout");
		iterations++;
	}

	cout << "Final error rate: " << error_rate << endl;

	return network;
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