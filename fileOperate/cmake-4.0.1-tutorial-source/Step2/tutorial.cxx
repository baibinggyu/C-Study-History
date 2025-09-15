// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "TutorialConfig.h"
// TODO 5: Include MathFunctions.h
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif
int main(int argc, char* argv[])
{
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << tutorial_VERSION_MAJOR << "."
              << tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  #ifdef USE_MYMATH
  double const inputValue = std::stod(argv[1]);
  #endif
  // TODO 6: Replace sqrt with mathfunctions::sqrt

  // calculate square root
  double const outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
