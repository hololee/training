//thread 사용하기 위해선 컴파일시 "-lpthread" 옵션을 줘야 함.
#include <iostream>
#include <queue>
#include <chrono>
#include <thread>
#include <mutex>

std::queue<int> q;
std::mutex m_mutex;

void thread_push()
{

    for (int i = 100; i < 10000; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        m_mutex.lock();
        q.push(i);
        m_mutex.unlock();
    }
}

void thread_pop(int n_thread)
{

    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        m_mutex.lock();
        if (q.size() > 0)
        {
            std::cout << "thread : " << n_thread << ",  get item :" << q.front() << std::endl;
            q.pop();
        }
        m_mutex.unlock();
    }
}

int main()
{

    std::thread t0(thread_push);
    std::thread t1(thread_pop, 1);
    std::thread t2(thread_pop, 2);
    std::thread t3(thread_pop, 3);
    std::thread t4(thread_pop, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}