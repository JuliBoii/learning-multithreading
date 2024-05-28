// Example of starting multiple threads
#include <iostream>
#include <thread>
#include <chrono>

void hello(const int& num) {
    // Add a delay
    std::this_thread::sleep_for(std::chrono::seconds(num));
    std::cout << "Hello from thread " << num << '\n';
}

int main() {
    std::cout << "Starting 3 threads:\n";
    // Start 3 threads
    std::thread thr1(hello, 1);
    std::thread thr2(hello, 2);
    std::thread thr3(hello, 3);

    // Wait for the threads to finish
    thr1.join();
    thr2.join();
    thr3.join();

    // Implementation for C++20
    /*std::jthread thr1(hello, 1);
    std::jthread thr2(hello, 2);
    std::jthread thr3(hello, 3);*/

    return 0;
}