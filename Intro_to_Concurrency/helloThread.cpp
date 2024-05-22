//
// Created by Angel Hernandez on 5/21/24.
//
// First program with std::thread
#include <iostream>
#include <thread>

// Callable object - thread entry point
void hello() {
    std::cout << "Hello, Thread!\n";
}

int main() {
    // Create an std::thread object
    // and pass the task function to the constructor
    std::thread thr(hello);

    // Wait for the thread to complete
    thr.join();

    return 0;
}