#include "dataDeal.h"
#include "../include/dataDeal.h"

#include <iostream>
#include <stdexcept>


vector<Data> FileRead(ifstream& file) {
    if (!file.is_open()) throw runtime_error("文件无法打开");
    vector<Data> ret;
    string line;
    getline(file, line); // 跳过标题栏
    while (getline(file, line)) {
        try {
            Data data = new DATA;
            if (data == nullptr) throw runtime_error("Date ERROR");
            data->time = new TIME;
            if (data->time == nullptr) throw runtime_error("data->time ERROR!");
            istringstream iss(line);
            string token;
            getline(iss, token, ',');
            data->id = std::stoi(token);
            getline(iss, token, ',');
            data->name = token;
            getline(iss, token, ',');
            if (token == "男") data->gender = male;
            else data->gender = female;
            getline(iss, token, ',');
            data->age = std::stoi(token);
            getline(iss, token, ',');
            data->department = token;
            getline(iss, token, ',');
            data->position = token;
            getline(iss, token, '-');
            data->time->Year = std::stoi(token);
            getline(iss, token, '-');
            data->time->Month = std::stoi(token);
            getline(iss, token, ',');
            data->time->Day = std::stoi(token);
            getline(iss, token, ',');
            data->salary = std::stoi(token);
            getline(iss, token, ',');
            data->phone = token;
            getline(iss, token);
            data->email = token;
            ret.push_back(data);
        }catch (exception& e) {cerr << "FileRead ERROR: " << e.what() << endl; }
    }
    return ret;
}
// 通过vector的push方法
bool FilePrint(vector<Data>& data) {
    for (vector<Data>::iterator it = data.begin(); it != data.end(); it++) {
        cout << "ID:" << (*it)->id << ',' << "name:" << (*it)->name << ',' << "age:" << (*it)->age << ','
        << "department:" << (*it)->department << ',' << "positon:" << (*it)->position << ','
        << "hire_date:" << (*it)->time->Year << '-' << (*it)->time->Month << '-' << (*it)->time->Day << ','
        << "salary:" << (*it)->salary << ',' << "phone:" << (*it)->phone << ','
        << "email:" << (*it)->email<< endl;
    }
    return true;
}

bool FileWrite(vector<Data>& data) {
    fstream file("managers.csv",std::ios::out);
    if (!file.is_open()) {cerr << "FILE SAVE OPEN FAILED!" << endl; return false;}
    file << "id,name,gender,age,department,position,hire_date,salary,phone,email" << endl;
    for (vector<Data>::iterator it = data.begin(); it != data.end(); it++) {
        file  << (*it)->id  << ','  << (*it)->name << ',' << (((*it)->gender == male) ? "男" : "女")<< ',' << (*it)->age << ','
       << (*it)->department << ',' << (*it)->position << ','
         << (*it)->time->Year << '-' << (*it)->time->Month << '-' << (*it)->time->Day << ','
        << (*it)->salary << ',' << (*it)->phone << ','
         << (*it)->email<< endl;
    }
    return true;
}