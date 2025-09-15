#include <iostream>
#include <list>
#include <iterator>
#include <stdexcept>
template<class T>
class vector{
public:
    vector(size_t size,T def):capacity(size),arr(size,def){}
    //深拷贝构造
    vector(const vector& vec){
        this->capacity = vec.capacity;
        this->arr = vec.arr;
    }
    size_t size(){return this->capacity;}
    void push_back(T element){
        this->arr.push_back(element);
        this->capacity++;
    }
    void pop_back(){
        if(this->arr.empty()) return;
        this->arr.pop_back();
        this->capacity--;
    }
    T& operator[](size_t index){
        if(index >= capacity) throw std::out_of_range("index out of range");
        typename std::list<T>::iterator it = this->arr.begin();
        while(index--)
            it++;
        return *it;
    }
    void erase(const T& element){
        typename std::list<T>::iterator it = this->arr.begin();
        while(*it != element) it++;
        if(it == this->arr.end()) return;
        this->arr.erase(it);
        this->capacity--;
    }
    ~vector(){}
private:
    size_t capacity;
    std::list<T> arr;
};