#ifndef __CHILD_H__
#define __CHILD_H__
#include "Base.h"
class Child: Base
{
public:
    Child(){
        std::cout << "Child construct " << std::endl;
    }
    ~Child(){
        std::cout << "Child delete " << std::endl;
    }
    Child(const Child& src):Base(src){
        std::cout << "Child copy " << std::endl;
    }
    Child& operator = (const Child& src){
        std::cout << "Child copy = " << std::endl;
    }
};
#endif
