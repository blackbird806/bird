#include <iostream>
#define BIRD_ENABLE_NAMESPACE
#include "Include/scope.hpp"

int main()
{
    
    SCOPE( std::cout << "first\n" );
    {
        SCOPE( std::cout << "hey\n" );
        SCOPE( std::cout << "hey2\n" );
        SCOPE( std::cout << "hey3\n" );
    }

    return 0;
}