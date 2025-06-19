#include <chrono>
#include <iostream>
#include "ThreadPool.h"
using namespace std;

class CalcWorker : public IWorker
{
public:
    CalcWorker(int id, int duration)
        : m_id(id), m_duration(duration) {}
    void doJob() override
    {
        cout << "Worker " << m_id << endl;

        // 每个worker的执行时间与其ID成正比
        this_thread::sleep_for(chrono::seconds(m_duration));

        m_processcount = m_id * 10;
        cout << "Worker " << m_id << " complete" << endl;
    }

    int getProcessCount() override
    {
        return m_processcount;
    }

private:
    int m_id;
    int m_duration;
    int m_processcount = 0;
};
