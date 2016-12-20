#include <iostream>
#include <thread>
#include <chrono>

namespace {
void sleep_ms(unsigned int time_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));
}
}

int main() {

    // Hello will not be printed until the end of the program.
    std::cout << "Hello";

    // Hello will be printed right away. 
    //std::cout << "Hello" << std::flush;
    
    sleep_ms(3000);

    std::cout << " World\n";

    return 0;
}

