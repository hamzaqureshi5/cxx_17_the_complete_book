#include <iostream>
#include <thread>

thread_local int counter = 0;

void work() {
    for (int i = 0; i < 3; i++) {
        counter++;
        std::cout << "Thread " << std::this_thread::get_id()
                  << " counter = " << counter << "\n";
    }
}

// int main() {
//     std::thread t1(work);
//     std::thread t2(work);

//     t1.join();
//     t2.join();
// }
