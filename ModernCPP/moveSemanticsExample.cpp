//
// Created by Angel Hernandez on 5/18/24.
//
// Program which passes a large object by value
#include <iostream>
#include <vector>
#include <string>

// Pass a value
// args will be a copy of the object passed by the caller
// void func(std::vector<std::string> arg) {
//     std::cout << "Argument vector has " << arg.size() << " elements" << std::endl;
// }

// This variation will not compile (before using std::move())
void func(std::vector<std::string>&& arg) {
    std::cout << "Argument vector has " << arg.size() << " elements" << std::endl;
}

int main() {
    std::vector<std::string> vec(1000000);

    std::cout << "Before calling func(), vector has " << vec.size() << " elements." << std::endl;

    // Pass by move
    // The object passed by the caller is moved into arg
    // Cast vec to an rvalue
    func(std::move(vec));
    std::cout << "After calling func(), vector has " << vec.size() << " elements." << std::endl;

    return 0;
}