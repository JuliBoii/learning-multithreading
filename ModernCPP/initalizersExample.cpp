//
// Created by Angel Hernandez on 5/17/24.
//

// Example of C++11 universal initializers
// Look at Notes.md for more detail
#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int x{5};
    const std::string str{"HEY I WAS INIT!"};

    std::cout << "x = " << x << std::endl;
    std::cout << "str = " << str << std::endl;

    // Narrowing conversions are not allowed
    constexpr int y = 7.7;    // will get a warning about potential loss of data
    // int y{7.7};

    std::cout << "y = " << y << std::endl;

    // can be used with multiple initial values
    const std::vector<int>vec{1, 4, 13, 52, 582, 8};

    std::cout << "vec = ";
    for (const auto& i : vec) std::cout << i << ", ";

    return 0;
}