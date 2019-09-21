#include <iostream>
#include "Include/scope.hpp"

struct foo
{
    foo() {};
    foo(foo const&) {std::cout << "copy\n";};
    foo(foo&&) {std::cout << "move\n";};
    void hello () const
    {
        std::cout << "hello\n";
    }
};

int main()
{
    SCOPE(std::cout << "end\n");
    std::cout << "hello" << std::endl;
    return 0;
} 