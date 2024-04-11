#include <iostream>
#include<chrono>
#include<thread>

int main() {
    int counter = 0;

    std::cout << "Count: " << counter << std::flush;

    // Loop 100 times
    for (int i = 0; i < 100; ++i) {

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ++counter;

        std::cout << "\rCount: " << counter << std::flush;
    }


    return 0;
}
