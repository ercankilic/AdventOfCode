#include "Day4.hpp"

#include <regex>
#include <string>

using namespace std;

void Day4::run()
{
    q1();
    q2();
}

inline bool Day4::is_in_range(int row, int col, int r, int c)
{
    return ((0 <= (row + r)) && ((row + r) < row_max) && (0 <= (col + c)) && ((col + c) < col_max));
}

void Day4::count_xmas(int row, int col)
{
    // horizontal
    if (is_in_range(row, col, 0, 3))
    {
        res += (letters[row][col] == 'X' && letters[row][col + 1] == 'M' && letters[row][col + 2] == 'A' &&
                letters[row][col + 3] == 'S')
                   ? 1
                   : 0;
    }

    // revere horizontal
    if (is_in_range(row, col, 0, -3))
    {
        res += (letters[row][col] == 'X' && letters[row][col - 1] == 'M' && letters[row][col - 2] == 'A' &&
                letters[row][col - 3] == 'S')
                   ? 1
                   : 0;
    }

    // vertical
    if (is_in_range(row, col, 3, 0))
    {
        res += (letters[row][col] == 'X' && letters[row + 1][col] == 'M' && letters[row + 2][col] == 'A' &&
                letters[row + 3][col] == 'S')
                   ? 1
                   : 0;
    }

    // reverse vertical
    if (is_in_range(row, col, -3, 0))
    {
        res += (letters[row][col] == 'X' && letters[row - 1][col] == 'M' && letters[row - 2][col] == 'A' &&
                letters[row - 3][col] == 'S')
                   ? 1
                   : 0;
    }

    // right bottom diagonal
    if (is_in_range(row, col, 3, 3))
    {
        res += (letters[row][col] == 'X' && letters[row + 1][col + 1] == 'M' && letters[row + 2][col + 2] == 'A' &&
                letters[row + 3][col + 3] == 'S')
                   ? 1
                   : 0;
    }

    // right up diagonal
    if (is_in_range(row, col, -3, 3))
    {
        res += (letters[row][col] == 'X' && letters[row - 1][col + 1] == 'M' && letters[row - 2][col + 2] == 'A' &&
                letters[row - 3][col + 3] == 'S')
                   ? 1
                   : 0;
    }

    // left bottom diagonal
    if (is_in_range(row, col, 3, -3))
    {
        res += (letters[row][col] == 'X' && letters[row + 1][col - 1] == 'M' && letters[row + 2][col - 2] == 'A' &&
                letters[row + 3][col - 3] == 'S')
                   ? 1
                   : 0;
    }

    // left up diagonal
    if (is_in_range(row, col, -3, -3))
    {
        res += (letters[row][col] == 'X' && letters[row - 1][col - 1] == 'M' && letters[row - 2][col - 2] == 'A' &&
                letters[row - 3][col - 3] == 'S')
                   ? 1
                   : 0;
    }
}

void Day4::q1()
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day4.txt").value();

    res = 0;
    string line;

    while (getline(input_file, line))
    {
        letters.emplace_back(vector<char>(line.begin(), line.end()));
    }
    input_file.close();

    row_max = letters.size();
    col_max = letters[0].size();

    for (int r = 0; r < row_max; ++r)
    {
        for (int c = 0; c < col_max; ++c)
        {
            count_xmas(r, c);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day4 Q1: Result: " << res << "\t| Time: " << elapsed.count() << "ms" << endl;
}

void Day4::count_mas(int row, int col)
{
    if (letters[row][col] != 'A')
    {
        return;
    }

    bool rb = false, lu = false, lb = false, ru = false;

    if (is_in_range(row, col, 1, 1) && is_in_range(row, col, -1, -1))
    {
        rb = (letters[row - 1][col - 1] == 'M' && letters[row + 1][col + 1] == 'S');

        ru = (letters[row + 1][col - 1] == 'M' && letters[row - 1][col + 1] == 'S');

        lb = (letters[row - 1][col + 1] == 'M' && letters[row + 1][col - 1] == 'S');

        lu = (letters[row + 1][col + 1] == 'M' && letters[row - 1][col - 1] == 'S');

        res += ((rb || lu) && (lb || ru)) ? 1 : 0;
    }
}

void Day4::q2()
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day4.txt").value();

    res = 0;
    letters.clear();
    string line;

    while (getline(input_file, line))
    {
        letters.emplace_back(vector<char>(line.begin(), line.end()));
    }

    input_file.close();

    row_max = letters.size();
    col_max = letters[0].size();

    for (int r = 1; r < row_max - 1; ++r)
    {
        for (int c = 1; c < col_max - 1; ++c)
        {
            count_mas(r, c);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day4 Q2: Result: " << res << "\t| Time: " << elapsed.count() << "ms" << endl;
}
