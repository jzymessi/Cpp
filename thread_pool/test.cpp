#include <iostream>
#include <thread>
#include "thread_pool/thread_pool.h"


int main()
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    ThreadPool tp(4, "inference");
    for (size_t i = 0; i < a.size(); i++)
    {
        /* code */
        tp.AddWork([i, &a](int pid){
            std::cout << "i: " << i << " a[i]: " << a[i] << std::endl;
        }, 0, true);
    }
    tp.WaitForWork();
    return 0;
}