#include <iostream>
#include <sstream>
using namespace std;
int main(void){
    // 字符串解析
    std::string logEntry = "2023-08-15 14:30:00 [WARNING] Disk 85% full";
    istringstream iss(logEntry);
    string date,time,isWARING,word,percent,isFull;
    getline(iss,date,' ');
    getline(iss,time,' ');
    getline(iss,isWARING,' ');
    getline(iss,word,' ');
    getline(iss,percent,' ');
    getline(iss,isFull);
    cout << "date: " << date << endl
    << "time: " << time << endl 
    << "isWARING: " << isWARING << endl
    << "word: " << word << endl
    << "percent: " << percent <<endl
    << "isFull: " << isFull << endl;
    return 0;
}