#ifndef __THREADPOOL__H
#define __THREADPOOL__H

#include<pthread.h>
#include<list>

#include "../lock/locker.h"

template<typename T>
class threadpool{
public:
    threadpool(int thread_number = 8,int max_request = 10000);
    ~threadpool();
    bool append(T* request);
    
private:
    static void* worker(void* arg);
    void run();
private:
    int m_thread_number;
    pthread_t * m_threads; //线程池数组
    //请求队列中最多允许的，等待处理的请求数量
    int m_max_request;
    std::list<T*> m_work_queue; //工作队列
    locker m_lock;//互斥锁
    //信号量用来判断是否有任务需要处理
    sem m_queuestat;
    bool m_stop;//是否结束线程

};
#endif