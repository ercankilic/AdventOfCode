#pragma once

#include <iostream>
#include <vector>
#include "ISolution.hpp"

class Day3 : public ISolution
{
public:
    Day3() = default;
    ~Day3() = default;

    void run() override;

private:
    void q1() const;
    void q2() const;
};
