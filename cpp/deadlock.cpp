#include <cstdio>
#include <thread>
#include <mutex>

static int buffer[2] = {0};
std::mutex buffer_mtx;

void writer()
{
    for (int i = 0; i < 50; ++i) {
        buffer_mtx.lock();
        buffer[0] = i;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        buffer[1] = i;
        buffer_mtx.unlock();
        printf("Buffer values written: (%d,%d)\n", i, i);
    }
}

void reader()
{
    for (int i = 0; i < 50; ++i) {
        buffer_mtx.lock();
        printf("Buffer values read: (%d, %d)\n", buffer[0], buffer[1]);
        buffer_mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main(void)
{
    std::thread t1(reader);
    std::thread t2(writer);
    t1.join();
    t2.join();

    return 0;
}

