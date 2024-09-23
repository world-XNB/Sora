#include <iostream>
#include "../inc/MyMath.hpp"
#include "../inc/StaticLib.hpp"
#include "../inc/SharedLib.hpp"

int main(int argc, char const *argv[])
{
    int a = 12;
    int b = 13;
    std::cout << "hello C++" << std::endl;
    std::cout  << "a + b = " << add(a, b) << std::endl;
    std::cout << "test static library" << std::endl;
    static_print();
    std::cout << "test shared library" << std::endl;
    shared_print();

    return 0;
}
