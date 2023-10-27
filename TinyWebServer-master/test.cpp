#include<iostream>
using namespace std;
union test
{
    short value;
    char arr[sizeof(short)];
};

int main()
{
    test t;
    t.value = 0x0102;
    if(t.arr[0]==1)
    {
        cout<<"daduan"<<endl;
    }
    else{
        cout<<"xiaoduan"<<endl;
    }
}
