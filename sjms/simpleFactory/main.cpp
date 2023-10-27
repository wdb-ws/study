#include <iostream>

#include "operatorFactory.h"
using namespace std;
int main()
{
    operatorFactory* fac = new operatorFactory();
    Operator* a = fac->createOperator('+');
    a->a = 1;
    a->b = 2;
    cout << a->getResult() << endl;
    return 0;
}