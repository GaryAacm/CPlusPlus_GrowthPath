#include "ThreadPool.h"
#include <cassert>
#include <iostream>

using namespace std;

Thread::Thread(IWorker *worker)
    : m_state(THREAD_CREATE), m_worker(worker)
{
    assert(worker != nullptr);
}

Thread::~Thread()
{
    delete m_worker; // 释放工作对象
}

void Thread::startThread()
{
    m_state = THREAD_CREATE;
    m_thread = thread(&Thread::run, this);
    m_thread.detach(); // 分离线程，使其独立运行
}

void Thread::run()
{
    m_state = THREAD_RUNNING;
    m_worker->doJob(); // 执行实际工作
    m_state = THREAD_END;
}

ThreadState Thread::getState() const
{
    return m_state;
}

int Thread::getProcessCount() const
{
    return m_worker->getProcessCount();
}

// ================= ThreadPool 类实现 =================
ThreadPool::ThreadPool() = default;

ThreadPool::~ThreadPool()
{
    for (Thread *thread : m_threads)
    {
        delete thread;
    }
    m_threads.clear();
}

void ThreadPool::addJob(IWorker *workPtr)
{
    assert(workPtr != nullptr);

    Thread *thread = new Thread(workPtr);
    thread->startThread();

    // 添加到线程列表
    std::lock_guard<std::mutex> lock(m_mutex);
    m_threads.push_back(thread);
}

size_t ThreadPool::getThreadNum() const
{
    std::lock_guard<mutex> lock(m_mutex);
    return m_threads.size();
}

bool ThreadPool::isAllFinish() const
{
    std::lock_guard<mutex> lock(m_mutex);
    for (Thread *thread : m_threads)
    {
        if (thread->getState() != THREAD_END)
        {
            return false;
        }
    }
    return true;
}

int ThreadPool::getProcessCount() const
{
    lock_guard<std::mutex> lock(m_mutex);
    int totalCount = 0;
    for (Thread *thread : m_threads)
    {
        totalCount += thread->getProcessCount();
    }
    return totalCount;
}


