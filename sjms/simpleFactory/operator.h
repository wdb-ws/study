#include <iostream>
using namespace std;

class Operator{
public:
    Operator() = default;
    virtual ~Operator(){};
    virtual double getResult() = 0;
    double a,b;
};

