#include <iostream>
#include <iomanip>  // for std::setw

#include "../inc/image.hpp"

void ImageGenerator::setPixel(int x, int y, int value) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		imagetemp[y][x] = value;
	}
}

void ImageGenerator::displayImage() const {
	for (const auto& row : imagetemp) {
		for (const auto& pixel : row) {
			// print each pixel with fixed width so columns align nicely
			std::cout << std::setw(3) << pixel << ' ';
		}
		std::cout << '\n';
	}
}

std::vector<std::vector<int>> & ImageGenerator::getImage() {
	return imagetemp;
}

void ImageProcessor::mirrorImage(ImageGenerator & imageGen) {
	int height = imageGen.getImage().size();
	int width = imageGen.getImage()[0].size();
	std::vector<std::vector<int>> mirrored(height, std::vector<int>(width));

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			mirrored[i][j] = imageGen.getImage()[i][width - 1 - j];
		}
		std::cout << std::endl; // New line after each row
	}

	imageGen.getImage() = mirrored; // Update the original image with the mirrored one
}

void ImageProcessor::invertImage(ImageGenerator & imageGen) {
	int height = imageGen.getImage().size();
	int width = imageGen.getImage()[0].size();
	std::vector<std::vector<int>> inverted(height, std::vector<int>(width));

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			inverted[i][j] = 255 - imageGen.getImage()[i][j]; // Assuming pixel values are in range [0, 255]
		}
	}

	imageGen.getImage() = inverted; // Update the original image with the inverted one
}