#include "Day3.hpp"

#include <regex>
#include <string>

using namespace std;

void Day3::run()
{
    q1();
    q2();
}

void Day3::q1() const
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day3.txt").value();

    const regex reg("mul\\(\\d+,\\d+\\)");
    int res = 0;
    string line;
    while (getline(input_file, line))
    {
        auto words_match = std::sregex_iterator(line.begin(), line.end(), reg);
        auto words_begin = words_match;
        auto words_end = std::sregex_iterator();

        for (; words_begin != words_end; ++words_begin)
        {
            string mul = words_begin->str();
            auto open_parentheses_index = mul.find('(');
            auto comma_index = mul.find(',');
            auto close_parentheses_index = mul.find(')');

            auto num1 = stoi(mul.substr(open_parentheses_index + 1, comma_index));
            auto num2 = stoi(mul.substr(comma_index + 1, close_parentheses_index));

            res += (num1 * num2);
        }
    }

    input_file.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day3 Q1: Result: " << res << "\t| Time: " << elapsed.count() << "ms" << endl;
}

void Day3::q2() const
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day3.txt").value();

    const regex reg_mul("mul\\(\\d{1,3},\\d{1,3}\\)|do\\(\\)|don't\\(\\)");

    int res = 0;
    string line;
    bool is_active = true;
    while (getline(input_file, line))
    {
        auto match = std::sregex_iterator(line.begin(), line.end(), reg_mul);
        std::sregex_iterator match_it = match;
        auto end_mul_it = std::sregex_iterator();

        for (; match_it != end_mul_it; match_it++)
        {
            string match_str = match_it->str();
            auto open_parentheses_index = match_str.find('(');

            if (open_parentheses_index == 2) // do
            {
                is_active = true;
            }
            else if (open_parentheses_index == 5) // don't
            {
                is_active = false;
            }
            else
            {
                if (is_active)
                {
                    auto comma_index = match_str.find(',');
                    auto close_parentheses_index = match_str.find(')');

                    auto num1 = stoi(match_str.substr(open_parentheses_index + 1, comma_index));
                    auto num2 = stoi(match_str.substr(comma_index + 1, close_parentheses_index));

                    res += (num1 * num2);
                }
            }
        }
    }
    input_file.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day3 Q2: Result: " << res << "\t| Time: " << elapsed.count() << "ms" << endl;
}
