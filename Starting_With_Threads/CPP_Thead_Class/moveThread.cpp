//
// Created by Angel Hernandez on 5/24/24.
//
// Example of passing a std::thread object to a function
#include <iostream>
#include <thread>

// The task function
void hello() {
    using namespace std::literals;
    std::this_thread::sleep_for(1s);
    std::cout << "Hello, Thread!\n";
}

// Function taking a thread object as argument
// The object must be moved into the arguement

// Good idea to add double ampersand
// When we have double ampersand and it is not a template parameter,
// that means it must be a rvalue, thus the caller must provide a rvalue
// Without them, it looks as either is accepted (l- or r-value)
void func(std::thread&& thr) {
    std::cout << "Received thread with ID " << thr.get_id() << std::endl;

    // The function argument now "owns" the system thread
    // It is responsible for calling join()
    thr.join();
}

int main() {
    // std::thread is a move-only object
    std::thread thr(hello);

    // Display the child thread's ID
    std::cout << "Hello thread has ID " << thr.get_id() << '\n';

    // Pass a named object using std::move()
    func(std::move(thr));

    // Pass a temp object
    // func(std::thread(hello));

    // Uncommenting thr.join() will crash the compiler
    // demonstration to show that the thread is no longer connected to main()
    // thr.join();
    return 0;
}
