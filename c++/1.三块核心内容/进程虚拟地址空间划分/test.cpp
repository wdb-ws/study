#include <iostream>
using namespace std;

int gdata1 = 10;
int gdata2 = 0;
int gdata3;

static int gdata4 = 11;
static int gdata5 = 0;
static int gdata6;

int main()
{
    const char* p = "hello world";
    //p[0] = 'a';Segmentation fault (core dumped)

    printf("%s",p);
    return 0;
}