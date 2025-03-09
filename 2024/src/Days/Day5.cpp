#include "Day5.hpp"

#include <cmath>
#include <map>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void Day5::run()
{
    q1();
    q2();
}

auto Day5::is_break_rule(vector<int> &rule, vector<int>::iterator &order_begin, vector<int>::iterator order_end)
{
    vector<int>::iterator find_it = order_end;

    for (const auto &r : rule)
    {
        if (find_it = find(order_begin, order_end, r); find_it != order_end)
        {
            break;
        }
    }

    return find_it;
}

bool Day5::sort_order(std::vector<int>::iterator order_it, std::vector<int>::iterator break_it,
                      std::vector<int>::iterator order_end, std::unordered_map<int, std::vector<int>> &rules)
{
    iter_swap(order_it, break_it);
    for (; order_it != order_end; ++order_it)
    {
        if (auto break_it = is_break_rule(rules[*order_it], order_it, order_end); break_it != order_end)
        {
            sort_order(order_it, break_it, order_end, rules);
        }
    }

    return true;
}

void Day5::q1()
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day5.txt").value();

    int res = 0;
    string line;
    map<int, vector<int>> rules;
    vector<vector<int>> orders;
    const regex decimal_reg("\\d+");

    while (getline(input_file, line))
    {
        if (auto del = line.find('|'); del != string::npos)
        {
            auto num1 = stoi(line.substr(0, del));
            auto num2 = stoi(line.substr(del + 1));

            if (rules.contains(num2))
            {
                rules.at(num2).emplace_back(num1);
            }
            else
            {
                rules[num2] = vector<int>{num1};
            }
        }
        else if (line.find(',') != string::npos)
        {
            auto decimal_match = sregex_iterator(line.begin(), line.end(), decimal_reg);
            auto decimal_match_it = decimal_match;
            auto decimal_match_end = sregex_iterator();
            vector<int> order;
            for (; decimal_match_it != decimal_match_end; ++decimal_match_it)
            {
                order.emplace_back(stoi(decimal_match_it->str()));
            }
            orders.emplace_back(order);
        }
    }
    input_file.close();

    for (auto &order : orders)
    {
        bool is_ordered = true;
        auto order_it = order.begin();
        for (; order_it != order.end(); ++order_it)
        {
            if (is_break_rule(rules[*order_it], order_it, order.end()) != order.end())
            {
                is_ordered = false;
                break;
            }
        }

        if (is_ordered)
        {
            auto mid = round(order.size() / 2);
            res += order.at(mid);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day5 Q1: Result: " << res << "\t| Time: " << elapsed.count() << "ms" << endl;
}

void Day5::q2()
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day5.txt").value();

    int res = 0;
    string line;
    unordered_map<int, vector<int>> rules;
    vector<vector<int>> orders;
    const regex decimal_reg("\\d+");

    while (getline(input_file, line))
    {
        if (auto del = line.find('|'); del != string::npos)
        {
            auto num1 = stoi(line.substr(0, del));
            auto num2 = stoi(line.substr(del + 1));

            if (rules.contains(num2))
            {
                rules.at(num2).emplace_back(num1);
            }
            else
            {
                rules[num2] = vector<int>{num1};
            }
        }
        else if (line.find(',') != string::npos)
        {
            auto decimal_match = sregex_iterator(line.begin(), line.end(), decimal_reg);
            auto decimal_match_it = decimal_match;
            auto decimal_match_end = sregex_iterator();
            vector<int> order;
            for (; decimal_match_it != decimal_match_end; ++decimal_match_it)
            {
                order.emplace_back(stoi(decimal_match_it->str()));
            }
            orders.emplace_back(order);
        }
    }
    input_file.close();

    for (auto &order : orders)
    {
        bool is_reordered = false;
        auto order_it = order.begin();
        for (; order_it != order.end(); ++order_it)
        {
            if (auto break_it = is_break_rule(rules[*order_it], order_it, order.end()); break_it != order.end())
            {
                is_reordered = sort_order(order_it, break_it, order.end(), rules);
                break;
            }
        }

        if (is_reordered)
        {
            auto mid = round(order.size() / 2);
            res += order.at(mid);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day5 Q2: Result: " << res << "\t| Time: " << elapsed.count() << "ms" << endl;
}
