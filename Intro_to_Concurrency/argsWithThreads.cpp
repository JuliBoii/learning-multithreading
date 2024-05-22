// Example of passing an argument to a thread function
#include <iostream>
#include <thread>
#include <string>

// Thread entry point
void hello(const std::string &str) {
    std::cout << str << "\n";
}

int main() {
    // hello() takes a string arg
    std::thread thr(hello, "Hello, Thread!");

    thr.join();

    return 0;
}