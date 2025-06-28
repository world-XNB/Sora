#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>


class ImageGenerator {
private:
	int width;
	int height;
	std::vector<std::vector <int>> imagetemp;

public:
	ImageGenerator(int w, int h) : width(w), height(h), imagetemp(h, std::vector<int>(w, 0)) {}

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