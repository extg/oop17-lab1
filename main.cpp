#include <iostream>
#include <fstream>      // std::ifstream

// Line-based parsing, using string streams:
#include <sstream>
#include <string>


inline bool is_file_exists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

int main() {
    const std::string FILENAME = "../input_files/lab01_input_correct_01.ini";

    if (!is_file_exists(FILENAME)) {
        std::cerr << "File " + FILENAME + " not exists." << std::endl;
    }

    std::ifstream file(FILENAME);

    std::string str;

    while (std::getline(file, str))
    {
        std::cout << str << std::endl;
    }

    return 0;
}
