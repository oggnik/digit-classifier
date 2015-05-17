#include "reader.h"


using namespace std;

uint32_t bytes_to_int(char bytes[4]) {
	uint32_t num;
	printf("%d %d %d %d\n", bytes[0] & 0xFF, bytes[1] & 0xFF, bytes[2] & 0xFF, bytes[3] & 0xFF);
	num = (((bytes[0] & 0xFF) << 24) | ((bytes[1] & 0xFF) << 16) | ((bytes[2] & 0xFF) << 8) | (bytes[3] & 0xFF));
	return num;
}


Image *read_dataset(string image_file_name, string label_file_name) {
	ifstream image_file;
	image_file.open(image_file_name, ios::in | ios::binary);

	if (!image_file.is_open()) {
		cout << "Error opening image file!";
		return NULL;
	}

	char magic_number[4];
	char num_items[4];
	char num_rows[4];
	char num_cols[4];

	image_file.read(magic_number, 4);
	image_file.read(num_items, 4);
	image_file.read(num_rows, 4);
	image_file.read(num_cols, 4);

	uint32_t num_images = bytes_to_int(num_items);

	// Allocate the array of images
	Image *images = new Image[num_images];

	// Read in the images
	char image[Image::IMAGE_SIZE];
	for (int x = 0; x < num_images; x++) {
		image_file.read(image, Image::IMAGE_SIZE);

		images[x].setImage(image);

		//printf("\n\n\nImage\n\n\n");
		//images[x].print();
	}

	image_file.close();


	ifstream label_file;
	label_file.open(label_file_name, ios::in | ios::binary);
	if (!label_file.is_open()) {
		cout << "Error opening label file!";
		return NULL;
	}

	// Read the labels

	label_file.read(magic_number, 4);
	label_file.read(num_items, 4);
	for (int x = 0; x < num_images; x++) {
		char label_data;
		label_file.read(&label_data, 1);
		uint32_t label = label_data & 0xFF;

		images[x].setLabel(label);

		printf("\n\n\nImage\n\n\n");
		images[x].print();
	}


	label_file.close();

	return images;
}