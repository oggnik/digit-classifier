#include <string>
#include <iostream>
#include <cstdint>
#include <vector>

#ifndef image_header

class Image {
	public:
		/**
		 * Constructor
		 */
		Image();

		/**
		 * Deconstructor
		 */
		~Image();

		/**
		 * The total size of an image in bytes
		 */
		static const int IMAGE_SIZE = 784;

		/**
		 * Set the image
		 */
		void setImage(char image[IMAGE_SIZE]);

		/**
		 * Get the image
		 */
		char *getImage();

		/**
		 * Set the label for the image
		 */
		void setLabel(uint32_t label);

		/**
		 * Get the label for the image
		 */
		uint32_t getLabel();

		/**
		 * Get the image as a double vector
		 * This is used as input to the neural network
		 */
		std::vector <double> getImageAsVector();

		/**
		 * Print the image to console
		 */
		void print();

	private:
		char *image_data;
		uint32_t label;
};

#define image_header
#endif