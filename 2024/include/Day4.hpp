#pragma once

#include "ISolution.hpp"
#include <array>
#include <iostream>
#include <vector>

class Day4 : public ISolution
{
  public:
    Day4() = default;
    ~Day4() = default;

    void run() override;

  private:
    void q1();
    void q2();
    inline bool is_in_range(int row, int col, int r, int c);
    void count_xmas(int row, int col);
    void count_mas(int row, int col);

    std::vector<std::vector<char>> letters;
    int row_max, col_max, res;
};
