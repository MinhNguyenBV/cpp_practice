#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream file("C:\\Users\\hi\\Desktop\\Funix\\C++\\practice\\stream\\test.txt");
	std::string line;

	if (file.is_open()) {

		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
		}

		file.close();
	}

	return 0;
}
