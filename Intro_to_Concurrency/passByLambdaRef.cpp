// Example of using a lambda expression as a thread's entry point
// The lambda caputes a local variable
#include <thread>
#include <iostream>

int main() {
    int i = 3;

    std::cout << "Value of i is " << i << '\n';

    // Use a lambda expression as the thread's entry point
    std::thread thr(
        // The first argument is the lambda expression
        [&i] {
            i *= 2;
        });

    thr.join();

    std::cout << "Value of i is now " << i << '\n';

    return 0;
}
