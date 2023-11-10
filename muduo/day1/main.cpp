#include <iostream>
#include "Base.h"
#include "Child.h"
using namespace std;

int main()
{
    Child c1;
    Child c2(c1);
    return 0;
}