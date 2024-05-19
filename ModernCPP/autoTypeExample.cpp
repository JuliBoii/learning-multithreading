//
// Created by Angel Hernandez on 5/18/24.
//
// Example of a loop in traditional c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{4, 2, 3, 5, 1};

    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    //     *it += 2;
    // }

    // using `auto` to simplify loops
    // for (auto it = vec.begin(); it != vec.end(); ++it) {
    //     *it += 2;
    // }

    // Further simplified range loop
    for (auto& i : vec) {
        i += 2;
    }

    std::cout << "Vector elements: ";

    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    //     std::cout << *it << ", ";
    // }

    // using `auto` to simplify loops
    // for (auto it = vec.begin(); it != vec.end(); ++it) {
    //     std::cout << *it << ", ";
    // }

    // std::cout << std::endl;

    // Further simplified range loop
    for (const auto& i : vec) {
        std::cout << i << ", ";
    }

    return 0;
}
