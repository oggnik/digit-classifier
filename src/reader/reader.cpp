#include "reader.h"
#include <iostream>

using namespace std;


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
	

	file.close();
}





int main(int argc, char **argv) {
	string file;
	cout << "Enter file name: ";
	cin >> file;
	read_image_file(file);

	return 0;
}