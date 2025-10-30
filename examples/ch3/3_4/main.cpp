



#include <thread>




#include "D.hpp"
#include "thread_l.hpp"
int main() {

// /* This Code is to understand thread local Only*/
// /* Simply each thread has its own copy of thrad local variable*/

    std::thread t1(work);
    std::thread t2(work);
    t1.join();
    t2.join();

// /* Exit Learning*/

return 0;

}
