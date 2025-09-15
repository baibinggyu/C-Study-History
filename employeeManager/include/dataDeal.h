#ifndef DATA_DEAL_H
#define DATA_DEAL_H

#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
enum GENDER {
    male = 0,
    female = 1,
};
typedef struct TIME {
    int Year;
    int Month;
    int Day;
}* Time;

typedef struct DATA {
    int id;
    string name;
    GENDER gender;
    int age;
    string department;
    string position;
    Time time;
    int salary;
    string phone;
    string email;
}* Data;

vector<Data> FileRead(ifstream& file);
// 通过vector的push方法
bool FilePrint(vector<Data>& data);

bool FileWrite(vector<Data>& data);

#endif

