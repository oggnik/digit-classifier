#include "../data/Image.h"
#include "../reader/Reader.h"
#include "../nn/NeuralNetwork.h"
#include "vector"

using namespace std;


int main(int argc, char **argv) {

	cout << "Loading training set" << endl;

	string training_image_file = "../data/train-images-idx3-ubyte";
	string training_label_file = "../data/train-labels-idx1-ubyte";

	Image *training_images = read_dataset(training_image_file, training_label_file);

	cout << "Training neural network" << endl;

	NeuralNetwork *network = new NeuralNetwork(784, 10, 3, 10);
	network->print();

	Image testImage = training_images[0];
	testImage.print();
	vector <double> output = network->computeOutput(testImage.getImageAsVector());

	cout << "Network output" << endl;
	for (int i = 0; i < output.size(); i++) {
		cout << "\t" << i << ": " << output[i] << endl;
	}

	cout << "asdf" << endl;

	delete[] training_images;

	cout << "fdas" << endl;

	delete network;

	cout << "fasdf" << endl;

	return 0;
}