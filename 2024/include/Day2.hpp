#pragma once

#include "ISolution.hpp"
#include <iostream>
#include <vector>

class Day2 : public ISolution
{
  public:
    Day2() = default;
    ~Day2() = default;

    void run() override;

  private:
    void q1() const;
    void q2() const;
    bool is_safe_report(std::vector<int> &vec) const;
};
