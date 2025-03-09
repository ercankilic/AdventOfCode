#pragma once

#include "ISolution.hpp"
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

class Day5 : public ISolution
{
  public:
    Day5() = default;
    ~Day5() = default;

    void run() override;

  private:
    void q1();
    void q2();

    auto is_break_rule(std::vector<int> &rule, std::vector<int>::iterator &order_begin,
                       std::vector<int>::iterator order_end);
    bool sort_order(std::vector<int>::iterator order_it, std::vector<int>::iterator break_it,
                    std::vector<int>::iterator order_end, std::unordered_map<int, std::vector<int>> &rules);
};
