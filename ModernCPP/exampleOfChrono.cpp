//
// Created by Angel Hernandez on 5/18/24.
//
#include <chrono>

// Namespce alias to simplify the code
namespace sc = std::chrono;

int main() {
    // Interval types defined in the std::chrono library
    sc::seconds(2);             // 2 second interval
    sc::milliseconds(20);       // 20 millisecond interval
    sc::microseconds(50);       // 50 microsecond interval

    // Using literal suffix added in C++14
    using namespace std::literals;
    2s;
    20ms;
    50us;

    // Should compile.

    return 0;
}