/*************************************************************************
    > File Name: MYDB.h
    > Author:wdb
    > Mail:1035059681@qq.com 
    > Created Time: 2023年06月2日 星期五 15时32分17秒
 ************************************************************************/


#include<iostream>
#include<mysql/mysql.h>
#include<string>
using namespace std;

class MYDB
{
    public:
    MYDB();
    ~MYDB();
    bool initDB(string host,string user,string pwd,string db_name); //连接数据库,host 主机名，用户名，密码，数据库名称
    bool exeSQL(string sql);   //执行sql语句
    private:
    MYSQL *mysql;          //连接mysql句柄指针
    MYSQL_RES *result;    //指向查询结果的指针
    MYSQL_ROW row;       //按行返回的查询信息
};
