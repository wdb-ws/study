#ifndef __BASH_H__
#define __BASH_H__

class Base
{
public:
    // Base(const Base& src){
    //     std::cout << "Base copy 构造函数" << std::endl;
    // }
    // Base& operator = (const Base& src)
    // {
    //     std::cout << "Base copy = 运算符" << std::endl;
    // }
    Base(const Base&) = default;
    Base& operator = (const Base&) = delete;
protected:
    // Base(){
    //     std::cout << "Base construct" << std::endl;
    // }
    // ~Base(){
    //     std::cout << "Base delete" << std::endl;
    // }
    Base() = default;
    ~Base() = default;

};
#endif