#include <fstream>
#include <iostream>


int main(int argc, char const *argv[])
{
    
    std::ofstream osm;
    osm.open("file.txt");

    if (!osm.is_open()) {
        std::cout << "file open filed." << std::endl;
    }

    osm << "abcd";


    return 0;
}
