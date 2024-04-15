#include<iostream>
#include<chrono>
#include<thread>


int main(){

    for(int i = 0; i < 200; i++){
        std::cout << "\ri = " << i << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}