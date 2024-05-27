// What happens to an std::thread object
// when an exception is throw?
#include <thread>
#include <iostream>

// Callable object - thread entry point
void hello() {
    std::cout << "Hello, Thread!\n";
}

// This will not compile properly
int main() {
    try {
        // Create an std::thread object
        std::thread thr(hello);

        // Code that might throw an exception
        throw std::exception();

        /*
         * The problem is that, when the exception is thrown
         * this will call the destructor of the thread object.
         * Occuring before join() has been called.
         * So, we have the thread object, which is being destroyed
         * without joining
         */
        thr.join();

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}