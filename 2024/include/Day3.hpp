#pragma once

#include "ISolution.hpp"
#include <iostream>
#include <vector>

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
