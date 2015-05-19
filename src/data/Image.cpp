#include "image.h"

using namespace std;

/**
 * Constructor
 */
Image::Image() {
	image_data = new char[IMAGE_SIZE];
	label = 0;
}

/**
 * Deconstructor
 */
Image::~Image() {
	delete[] image_data;
}

/**
 * Copy the contents of the given image into image_data
 */
void Image::setImage(char image[IMAGE_SIZE]) {
	for (int i = 0; i < IMAGE_SIZE; i++) {
		image_data[i] = image[i];
	}
}

/**
 * Get the image
 */
char *Image::getImage() {
	return image_data;
}


/**
 * Set the label for the image
 */
void Image::setLabel(uint32_t image_label) {
	label = image_label;
}

/**
 * Get the label for the image
 */
uint32_t Image::getLabel() {
	return label;
}

/**
 * Get the image as a double vector
 * This is used as input to the neural network
 */
vector <double> Image::getImageAsVector() {
	vector <double> imageValues(IMAGE_SIZE);

	for (int i = 0; i < IMAGE_SIZE; i++) {
		uint32_t pixel = 0 | (image_data[i] & 0xFF);
		imageValues[i] = (double) pixel;
	}

	return imageValues;
}

/**
 * Print the image to console
 */
void Image::print() {
	printf("Image label: %d\n", label);
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 28; j++) {
			uint32_t pixel = 0 | (image_data[i * 28 + j] & 0xFF);
			if (pixel == 0) {
				printf(" ");
			} else {
				printf("%c", 219);
			}
		}
		cout << endl;
	}
}