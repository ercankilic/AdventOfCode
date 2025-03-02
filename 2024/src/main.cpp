#include <iostream>
#include <array>
#include <memory>

#include "Days.hpp"

using namespace std;

int main()
{
    array<unique_ptr<ISolution>, 2> 
        days = {make_unique<Day1>(),
                make_unique<Day2>()};

    for (const auto &d : days)
    {
        d->run();
    }

    return 0;
}
