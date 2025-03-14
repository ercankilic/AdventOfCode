#pragma once

#include "ISolution.hpp"
#include <iostream>

class Day1 : public ISolution
{
  public:
    Day1() = default;
    ~Day1() = default;

    void run() override;

  private:
    void q1() const;
    void q2() const;
};
