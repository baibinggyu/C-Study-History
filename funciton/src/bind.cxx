    #include <iostream>
    #include <string>
    #include <functional>


    void Print(const std::string& s1,const std::string& s2){
        std::cout << s1 << s2 << std::endl;
    }
    void func(std::function<void(std::string& s3)> p,std::string s3){
    p(s3);
    }
    int main(void){
        std::string s1{"Hello"};
        std::string s2{"World!"};
        std::string s3("HI");
        
        // auto p = std::bind(Print,s1,s2);
        // std::function<void()> p = std::bind(Print,s1,s2);
        // p();
        std::function<void(std::string& s3)> p = bind(Print,std::placeholders::_1,s2);
        p(s3);
        func(p,s3);
        


        return 0;
    }