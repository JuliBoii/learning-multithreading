// Example of a thread which throws an uncaught exception
#include <thread>
#include <iostream>

// Task function
void hello() {
    try {
        throw std::exception();
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    std::cout << "Hello, Thread!\n";
}

int main() {
    // Create an std::thread object
    std::thread thr(hello);
    thr.join();

    // Check that the program is still running
    std::cout << "Finished\n";

    return 0;
}


/* Try Catch in the main function will cause the
 * whole program to crash

void hello() {
    throw std::exception();

    std::cout << "Hello, Thread!\n";
}

int main() {
    // Create an std::thread object
    try {
        std::thread thr{hello};
        thr.join();

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    // Check that the program is still running
    std::cout << "Finished\n";

    return 0;
}*/