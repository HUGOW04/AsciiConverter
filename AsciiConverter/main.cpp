#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	std::string input;

	std::cout << "Input the name of image: " << std::endl;
	std::cin >> input;
	std::cout << std::endl;

	sf::Image img;
	if (!img.loadFromFile(input))
	{
		return 1;
	}
	else
	{
		std::cout << "Image loaded..." << std::endl;
	}

	ofstream result("result.txt");

	char tab[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

	sf::Vector2u size_img;
	size_img = img.getSize();

	sf::Color pixel;
	int gray = 0;
	int num = 0;

	for (int i = 0; i < size_img.y; i++)
	{
		for (int j = 0; j < size_img.x; j++)
		{
			pixel = img.getPixel(j, i);
			gray = 0.2989 * pixel.r + 0.5870 * pixel.g + 0.1140 * pixel.b;
			num = floor(gray / 25.6);
			result.put(tab[9 - num]);
		}
		result.put('\n');
	}
	result.close();
	std::cout << "Done" << std::endl;
	std::cout << std::endl;

}