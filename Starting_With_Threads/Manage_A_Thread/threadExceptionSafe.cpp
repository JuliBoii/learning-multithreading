// Safely destroying an std::thread object
// When an exception is thrown (verbose)
#include <iostream>
#include <thread>

// Callable object - thread entry point
void hello() {
    std::cout << "Hello, Thread!\n";
}

int main() {
    // Create an std::thread object
    std::thread thr(hello);

    try {
        // Code that might throw an exception
        // throw std::exception();

        // No exception if we got here - call join() as usual
        thr.join();
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
        thr.join();     // Call join before thr's destructor is called
    }

    return 0;
} // Calls ~thr()