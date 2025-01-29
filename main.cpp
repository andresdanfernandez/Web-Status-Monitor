#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Error incorrect arguement count\n";
        return 1;
    }

    // returns a file descriptor (an int that is non-negative unless socket error)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
    std::cerr << "Error creating socket\n";
    return -1;
    }

    // this is a struct that specifies the IP address and port number
    struct sockaddr_in server_addr; 

    // AF_INET for TCP
    server_addr.sin_family = AF_INET;
    // we use htons to convert 8080 to network byte order
    server_addr.sin_port = htons(8080);

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

    // we want to figure out whether we see http or https

    for(std::string url : urls) {
        if(url.find("https") != std::string::npos) {
            std::cout << url << '\n';
        } else {
            std::cout << url << '\n';
        }
    }

    close(sockfd);
    file.close();
    
    return 0;
}