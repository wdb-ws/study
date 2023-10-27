#include<iostream>
#include"MYDB.h"
using namespace std;
int main()
{
    cout<<"hello world"<<endl;
    MYDB db; 
    //连接数据库
    db.initDB("localhost","root","ws20020627","itheima");
    
    db.exeSQL("SELECT * from account;");
    return 0;
}