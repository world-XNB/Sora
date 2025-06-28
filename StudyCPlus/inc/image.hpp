#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include <random>  // for random number generation

class ImageGenerator {
private:
	int width;
	int height;
	std::vector<std::vector <int>> imagetemp;

public:
	// constructor initializes the image buffer and fills with random values in [0,255]
	ImageGenerator(int w, int h) : width(w), height(h), imagetemp(h, std::vector<int>(w)) {
		// create random engine and distribution
		std::mt19937 rng(std::random_device{}());
		std::uniform_int_distribution<int> dist(0, 255);
		for (auto &row : imagetemp) {
			for (auto &pixel : row) {
				pixel = dist(rng);
			}
		}
	}

	void setPixel(int x, int y, int value);

	void displayImage() const;

	std::vector<std::vector<int>> & getImage();
};

class ImageProcessor {
private:
	std::vector<std::vector <int>> imagetemp;

public:
	void mirrorImage(ImageGenerator & imageGen);

	void invertImage(ImageGenerator & imageGen);
};


#endif // IMAGE_HPP