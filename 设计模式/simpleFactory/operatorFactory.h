#include <iostream>
#include "operator.h"
#include "operatorAdd.h"
using namespace std;

class operatorFactory{
public:
    operatorFactory() = default;
    static Operator* createOperator(const char oper){
        Operator* op = nullptr;
        switch (oper)
        {
        case '+':
            op = new OperatorAdd();
            break;
        
        default:
            break;
        }
        return op;
    }
};