#include "threadpool.h"
#include <iostream>
#include <exception>
#include <pthread.h>
using namespace std;

template<typename T>
threadpool<T>::threadpool(int thread_number,int max_request):m_thread_number(thread_number),
    m_max_request(max_request),m_stop(false),m_thread(NULL){
            if(thread_number <= 0 || max_request <= 0)
            {
                throw std::exception();
            }

            m_threads = new pthread_t [thread_number];

            if(!m_threads)
            {
                throw std::exception();
            }

            for(int i=0;i<thread_number;i++)
            {
                cout << "创建第" << i << "个线程 " <<endl;
                
                if(pthread_create(m_threads + i, NULL, worker, this) != 0)
                {
                    delete [] m_threads;
                    throw std::exception();
                }

                pthread_detach(m_threads[i]);
        
            }
    }

template<typename T>
threadpool<T>::~threadpool()
{
    delete [] m_threads;
    m_stop = false;
}

template<typename T>
bool threadpool<T>::append(T* request)
{   
    m_lock.lock(); // 上锁
    if(m_work_queue.size() > m_max_request)
    {
        m_lock.unlock(); // 解锁
        return false;
    }

    m_work_queue.push_back(request);
    m_lock.unlock();

    m_queuestat.post();
    return true;
}

template<typename T>
void* threadpool<T>::worker(void* arg)
{
    threadpool * pool = static_cast<threadpool*> arg;
    pool.run();
    return pool;
    
}

template<typename T>
void threadpool<T>::run()
{
    cout << "线程运行 " << endl;
    while(!m_stop)
    {
        m_queuestat.wait();
        m_lock.lock();
        if(!m_work_queue.empty())
        {
            T* request = m_work_queue.front();
            m_work_queue.pop_front();
            m_lock.unlock();
            if(!request)
            {
                continue;
            }

            request->process();
            
        }
        else{
            m_lock.unlock();
            continue;
        }

    }
}