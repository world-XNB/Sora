#include <iostream>
#include <vector>

#include "../inc/image.hpp"

using std::vector;

void printMessage() {
	vector<int> vi(5);
	vi[0] = 1;
	vi[1] = 2;
	vi[2] = 3;
	vi[3] = 4;
	vi[4] = 5;
	for (int i = 0; i < vi.size(); ++i) {
		std::cout << "Element " << i << ": " << vi[i] << std::endl;
	}

	std::cout << "This is a message from the printMessage function." << std::endl;
}

int main() {
	std::cout << "Hello, C++ World!" << std::endl;
	printMessage();

	ImageGenerator imgGen(5, 5);
	imgGen.displayImage();

	std::cout << "invertImage" << std::endl;
	ImageProcessor imgProc;
	imgProc.invertImage(imgGen);
	imgGen.displayImage();

	return 0;
}
