#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Error incorrect arguement count\n";
        return 1;
    }

    std::string filename = argv[1];

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error could not open file\n";
        return 1;
    }

    std::cout << "File Opened!\n";

    std::string url;

    std::vector<std::string> urls;

    while (std::getline(file, url)) {
        urls.push_back(url);
    }

    for(std::string url : urls) {
        std::cout << url << '\n';
    }

    file.close();
    return 0;
}