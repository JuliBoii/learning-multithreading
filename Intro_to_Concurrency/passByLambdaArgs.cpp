// Example of using a lambda expression as a thread's entry point
// The lambda takes arguments
#include <thread>
#include <iostream>

int main() {
    // Use a lambda expression as the thread's entry point
    std::thread thr(
        // The first argument is the lambda expression
        [] (int i, int j) {
            std::cout << "The sum of " << i << " and " << j << " is " << i + j << '\n';
        },

        // The remaining arguments are passed to the lambda expression
        2, 3
    );

    thr.join();

    return 0;
}