#include "../data/image.h"
#include "../reader/reader.h"
#include "../nn/NeuralNetwork.h"

using namespace std;


int main(int argc, char **argv) {

	cout << "Loading training set" << endl;

	string training_image_file = "../data/train-images-idx3-ubyte";
	string training_label_file = "../data/train-labels-idx1-ubyte";

	Image *training_images = read_dataset(training_image_file, training_label_file);

	cout << "Training neural network" << endl;

	NeuralNetwork *network = new NeuralNetwork(784, 10, 3, 10);
	network->print();

	delete[] training_images;
	delete network;

	return 0;
}