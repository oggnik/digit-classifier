#include "reader.h"
#include <iostream>
#include <fstream>

using namespace std;

int bytes_to_int(char bytes[4]) {
	int num;
	num = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
	return num;
}

void read_image_file(string file_name) {
	ifstream file;
	file.open(file_name, ios::in | ios::binary);

	if (!file.is_open()) {
		cout << "Error opening file!";
		return;
	}

	char magic_number[4];
	char num_items[4];
	char num_rows[4];
	char num_cols[4];

	char image[784];
	file.read(magic_number, 4);
	file.read(num_items, 4);
	file.read(num_rows, 4);
	file.read(num_cols, 4);
	file.read(image, 784);

	cout << bytes_to_int(num_rows) << endl;

	file.close();
}





int main(int argc, char **argv) {
	string file;
	cout << "Enter file name: ";
	file = "../../data/train-images-idx3-ubyte";
	//cin >> file;
	read_image_file(file);

	return 0;
}