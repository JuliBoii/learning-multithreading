//
// Created by Angel Hernandez on 5/24/24.
//
// Example of returning a std::thread object from a function
#include <thread>
#include <iostream>

// Task function for the thread
void hello() {
    std::cout << "Hello, Thread!\n";
}

// Fucntion returning a std::thread object
std::thread func() {
    // Start the thread
    std::thread thr(hello);

    // Return a local variable
    return thr;

    // Return a temp object
    // return std::thread(hello);
}

int main() {
    // Call a function which return
    std::thread thr = func();

    std::cout << "Received thread with ID " << thr.get_id() << '\n';

    // Our thr object now "owns" the system thread
    // It is responsible for calling join()
    thr.join();

    return 0;
}