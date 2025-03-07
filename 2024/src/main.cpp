#include <iostream>
#include <array>
#include <memory>

#include "Days.hpp"

using namespace std;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    array<unique_ptr<ISolution>, 4> 
        days = {make_unique<Day1>(),
                make_unique<Day2>(),
                make_unique<Day3>(),
                make_unique<Day4>()
               };

    for (const auto &d : days)
    {
        d->run();
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Total time spend: " << elapsed.count() << "ms" << endl;
    return 0;
}
