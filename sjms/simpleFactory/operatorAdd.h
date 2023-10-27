#include <iostream>

using namespace std;

class OperatorAdd: public Operator
{
public:
    OperatorAdd() = default;
    ~OperatorAdd(){}
    double getResult() override{
        double result = a + b;
        return result;
    }

};