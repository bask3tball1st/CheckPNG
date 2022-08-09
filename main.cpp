#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main() {
	std::ifstream in;
	std::string fileName;
	std::cout << "Enter file path: ";
	std::cin >> fileName;
	int pos = fileName.find(".");
	if (fileName.substr(pos + 1) == "png") {
		in.open("" + fileName + "", std::ios::binary);
		if (in.is_open()) {
      char png[] = {-119, 'P', 'N', 'G', 0};
			while (in.good()) {
				char buffer[5];
				in.read(buffer, sizeof(buffer));
				buffer[4] = 0;
				if (std::strcmp(buffer, png) == 0) {
					std::cout << "The file was successfully checked for png!" << std::endl;
					break;
				}
				else {
					std::cout << "The file did not pass the PNG check!" << std::endl;
					break;
				}
			}
		}
	}
	else
		std::cout << "The file is not PNG extension!" << std::endl;
	in.close();
	return 0;
}