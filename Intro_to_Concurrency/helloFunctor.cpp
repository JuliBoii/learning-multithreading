//
// Created by Angel Hernandez on 5/21/24.
//
#include <iostream>
#include <thread>

// Functor class with overloaded () operator
class Hello {
public:
    void operator()() const { std::cout << "Hello, Functor!\n"; }
};

int main() {
    // Creates an object of the functor class
    Hello hello;

    // Pass the onject to std::thread's constructor
    std::thread thr(hello);

    // Wait for the thread to complete
    thr.join();

    return 0;
}