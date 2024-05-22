//
// Created by Angel Hernandez on 5/21/24.
//
// Example using a lambda expression as a thread's entry point
#include <iostream>
#include <thread>

int main() {
    // Use a lambda expression as the thread's entry point
    std::thread thr([]() { std::cout << "Hello, Lambda Thread!\n"; });

    thr.join();

    return 0;
}