#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    double input = std::stod(argv[1]);
    double result = std::sqrt(input);
    
    std::cout << input << " is " << result << std::endl;
    return 0;
} 