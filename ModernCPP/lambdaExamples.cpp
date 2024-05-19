//
// Created by Angel Hernandez on 5/18/24.
//
// Examples of lambda expression syntax
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // In C++14, the compiler can deduce the return type
    // [] (int arg) { return 2 * arg; };

    // In C++11, it must be specified with a trailing return type
    // [] (int arg) -> int { arg = 2 * arg; return arg; };

    // A lambda expression is a callable object
    // It can be invoked by putting () after the body, with any arguments
    std::cout << "Inline Example lambda fucntion: " <<
        [] (int arg) {return 2 * arg; }(3) << std::endl << std::endl;

    // A lambda expression can be stored in a variable of type "auto"
    auto lam = [] (int arg) { return 2 * arg; };

    std::cout << "Calling variable lam with argument 3\n";
    std::cout << "Returns: " << lam(3) << std::endl << std::endl;;

    int n = 2;

    // Algorithm call with p
    // Captures the local variable n by reference
    std::cout << "Inline Example lambda fucntion: " <<
        [&n] (int arg) { return (++n * arg); }(3) << std::endl;

    std::cout << "n = " << n << std::endl << std::endl;

    std::vector<int>vec{4, 2, 3, 5, 1};

    std::cout << "Elements of vector: ";

    for (const auto& i : vec) std::cout << i << ", ";

    std::cout << std::endl;

    int radix = 3;

    // Call std::count_if() algroithm using a lambda expression as predicate
    auto n_even = std::count_if(vec.begin(), vec.end(),
        // The lambda definition goes inside the call!
        [radix] (int n) { return (n % radix == 0); }
    );

    std::cout << "The vector has " << n_even << " element(s) which are exact multiples of " << radix << std::endl;

    return 0;
}