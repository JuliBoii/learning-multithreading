// UnSynchronized threads which make conflicting accesses.
// But where is the shared memory location?
#include <thread>
#include <iostream>
#include <string>

void print(const std::string& str) {
    // A very artificial way to display a string
    for (int i = 0; i < 5; i++) {
        // It is cout
        /* Cout is actually a global object with class ostream
         * we have the threads accessing cout concurrently
         * the left shift function call, is modifying cout
         * because it writes data into the stream
         */
        // The output is scrambled because the thread behavior
        // is not defined
        std::cout << str[0] << str[1] << str[2] << std::endl;
    }
}

int main() {
    std::jthread thr1(print, "abc");
    std::jthread thr2(print, "def");
    std::jthread thr3(print, "xyz");

    return 0;
}