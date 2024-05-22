// Example of passing arguments to a thread function by move
#include <iostream>
#include <thread>
#include <string>

// Thread entry point function
// Requires an rvalue argument
void func(std::string&& str) {
    std::cout << "Ownership of \"" << str << "\" transferred to thread" << "\n";
}

int main() {
    std::string str = "moveable";

    std::cout << "Starting thread\n";

    // Wrap str in a call to std::move()
    std::thread thr(func, std::move(str));

    thr.join();

    return 0;
}