#include "head/main.h"
#include "mainConfig_file.h"
int main(int argc,char* argv[])
{
    if(argc != 2) {cout << "Usage:" << argc << endl;return -1;}
    const double inputValue = std::stod(argv[1]);
    cout << inputValue << endl;
    cout << "__cplusplus:" << __cplusplus << endl;
    cout << "main_VERSION_MAJOR:" << main_VERSION_MAJOR << endl;
    cout << "main_VERSION_MINOR:" << main_VERSION_MINOR << endl;
    cout << "STR_TEST:" << STR_TEST << endl;
    return 0;
}