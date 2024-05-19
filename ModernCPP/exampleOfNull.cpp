//
// Created by Angel Hernandez on 5/18/24.
//
// Example of NUll v. C++11's nullptr
#include <iostream>

// Two functions which are overloaded
// g++ does not know which function to call
void func(int i) { std::cout << "func(int) called" << std::endl; }

void func(int* i) { std::cout << "func(int* i) called" << std::endl; }

int main() {
    // func(NULL);  // Will not compile with gcc or g++
    func(nullptr);

    return 0;
}