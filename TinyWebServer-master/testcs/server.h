#ifndef __SERVER__H
#define __SERVER__H
#include<iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <cassert>
#include <sys/epoll.h>
#include <./http_conn/http_conn.h>
#include <./threadpool/threadpool.h>
#include <./timer/lst_timer.h>
class server{
public:
    server();
    ~server();
    void init();
    void EventListen();
    void EventLoop();
    bool dealclinetdata();
    void dealwithread(int sockfd);
private:
    int m_port;
    int m_listenfd;
    epoll_event events[10000];
    int m_epollfd;
    int LT_ET_mode = 1;
    int pro_re = 0;
    threadpool<http_conn> *m_pool;
    http_conn * users;
    
};
#endif