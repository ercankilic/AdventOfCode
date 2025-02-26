#include <iostream>
#include <array>
#include <memory>

#include "Days.hpp"

using namespace std;

int main()
{
    array<unique_ptr<ISolution>, 1> days = {make_unique<Day1>()};

    for (const auto &d : days)
    {
        d->run();
    }

    return 0;
}
