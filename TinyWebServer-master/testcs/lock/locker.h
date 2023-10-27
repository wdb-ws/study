#ifndef __LOCK__H
#define __LOCK__H


#include<pthread.h>
#include<exception>
#include<iostream>
#include <semaphore.h>



class locker{
public:
    locker(){
        
        if(pthread_mutex_init(&m_mutex,NULL)!=0)
        {
            throw std::exception();
        }
    }
    ~locker(){
        pthread_mutex_destroy(&m_mutex);
    }

    bool lock(){
        return pthread_mutex_lock(&m_mutex) == 0;
    }
    bool unlock(){
        return pthread_mutex_unlock(&m_mutex) == 0;
    }
private:
    pthread_mutex_t m_mutex;
};

class sem{
public:
    sem(){
        if(sem_init(&m_sem,0,0) != 0){
            throw std::exception();
        }
    }
    sem(int num){
        if(sem_init(&m_sem,0,num) != 0){
            throw std::exception();
        }
    }
    bool wait(){
        return sem_wait(&m_sem) == 0;
    }
    bool post(){
        return sem_post(&m_sem) == 0;
    }
    ~sem(){

    }
private:

    sem_t m_sem;
};
#endif