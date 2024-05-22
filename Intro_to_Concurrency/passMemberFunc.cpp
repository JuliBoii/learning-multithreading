// Example of using a member function as thread's entry point
#include <iostream>
#include <thread>

// Class whose member function
// will be used as the thread's entry point
class Greeter {
public:
    void hello() {
        std::cout << "Hello, Member Function Thread!\n";
    }
};

int main() {
    // Create an object of the class
    Greeter greet;

    // Create an std::thread object
    // Pass a pointer to the member function
    std::thread thr(&Greeter::hello, &greet);

    thr.join();

    return 0;
}