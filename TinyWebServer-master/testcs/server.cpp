
#include"server.h"

#define MAX_FD 65535
using namespace std;

server::server()
{
    m_port = 9999;
}

server::~server()
{

}

void server::init()
{
    m_pool = NULL;
    try
    {
        m_pool = new threadpool<http_conn>;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    http_conn * users = new http_conn [MAX_FD];
    
}

bool server::dealclinetdata()
{
    struct sockaddr_in client_address;
    //ET模式
    if(LT_ET_mode == 1){
        while (1)
        {
            int connfd = accept(m_listenfd, (struct sockaddr *)&client_address, &client_address);

        }
        return false;
    }
    else{
        int connfd = accept(m_listenfd, (struct sockaddr *)&client_address, &client_address); 
    }
    return true;
}
void server::dealwithread(int sockfd)
{
    if(pro_re == 0) //同步I/O模拟proactor
    {
        
    }
}
void server::EventListen()
{
    int m_listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(m_listenfd >= 0);
    struct sockaddr_in address;
    //bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(m_port);
    int ret = bind(m_listenfd,(struct sockaddr*)&address,sizeof(address));
    assert(ret>=0);
    
    ret = listen(m_listenfd, 5);
    assert(ret >= 0);

    epoll_event events[10000];

    m_epollfd = epoll_create(5);
    assert(m_epollfd != -1);
    util.addfd(m_epollfd,m_listenfd,true,1);
}
void server:: EventLoop()
{
    bool server_run = true;
    while(server_run)
    {
        int number = epoll_wait(m_epollfd,events,10000,-1);
        cout<<number<<endl;
        for(int i=0;i<number;i++)
        {
            int sockfd = events[i].data.fd;
            //处理到新的客户连接
            if(sockfd == m_listenfd)
            {
                bool flag = dealclinetdata();
                if(flag == false)
                {
                    continue;
                }
            }
            else if (events[i].events & EPOLLIN)
            {
                //cout<<"epollin"<<endl;
                //cout<<"event[i].events:"<<events[i].events<<endl;
                dealwithread(sockfd);
            }
            else if (events[i].events & EPOLLOUT)
            {
                //cout<<"epollout"<<endl;
                //cout<<"event[i].events:"<<events[i].events<<endl;
                dealwithwrite(sockfd);
            }
        }
    }
}