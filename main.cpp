#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/socket.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Error incorrect arguement count\n";
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
    std::cerr << "Error creating socket\n";
    return -1;
    }

    std::string filename = argv[1];

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error could not open file\n";
        return 1;
    }

    // if protocol is http, web server listening at port 80.
    // else if it is https, web server listening at port 443.
    // in the url example "fiu.gov" is the host name which must be translated to an IP address.

    std::cout << "File Opened!\n";

    std::string url;

    std::vector<std::string> urls;

    while (std::getline(file, url)) {
        urls.push_back(url);
    }

    // start with one url -> http://fiu.gov
    std::string firstUrl = urls[0];





    file.close();
    return 0;
}