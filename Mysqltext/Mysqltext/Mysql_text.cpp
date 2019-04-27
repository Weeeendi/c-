#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <iostream>  
#include "winsock.h"  
#include "mysql.h"  
using namespace std;  
#pragma comment (lib, "libmysql.lib")  
#pragma comment (lib, "mysqlclient.lib")  
  
int main()  
{  
    //connectionparams  
    char *host = "localhost";  
    char *user = "root";//mysql的用户名  
    char *pass = "wendi1995";//你的mysql服务器密码  
    char *db = "MySql";  
    unsigned int port = 3308; //server port  
    MYSQL *sock;  
    sock=mysql_init(0);  
    if(sock &&mysql_real_connect(sock,host,user,pass,db,0,NULL,0))  
    {  
        cout<<"connect mysqlsucceed!"<<endl;  
    }  
    else  
    {  
        cout<<"I'm sorry to tell you that you wrong!"<<endl;  
    }  
    getchar();  
    //input 1 or 2 or 3  
    return 0;  
}  
