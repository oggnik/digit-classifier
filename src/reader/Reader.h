#include <cstdint>
#include <iostream>
#include <fstream>
#include "../data/Image.h"

#ifndef reader_header

/**
 * Read in the specified dataset and return all the images
 */
Image *read_dataset(std::string image_file_name, std::string label_file_name);
uint32_t bytes_to_int(char bytes[4]);

#define reader_header
#endif