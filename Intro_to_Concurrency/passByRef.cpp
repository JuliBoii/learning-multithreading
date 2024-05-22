// Example of passing arguments to a thread function by reference
#include <iostream>
#include <thread>
#include <string>

// Thread entry point
void hello(std::string& str) {
    str = "xyz";
}

int main() {
    std::string str = "abc";

    std::cout << "str is: " << str << '\n';

    // Wrap argument in a call to std::ref()
    std::thread thr(hello, std::ref(str));

    thr.join();

    // Verify that it has been modified
    std::cout << "str is now: " << str << '\n';

    return 0;
}