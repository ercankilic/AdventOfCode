#include <fstream>
#include <string>

#include "Day2.hpp"

using namespace std;

void Day2::run()
{
    q1();
    q2();
}

void Day2::q1() const
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day2.txt").value();

    string line;

    int safe_counter = 0;
    while (getline(input_file, line))
    {
        string val;
        stringstream ss(line);

        getline(ss, val, ' ');
        int num1 = stoi(val);

        getline(ss, val, ' ');
        int num2 = stoi(val);

        bool is_safe = true;
        bool is_continue = true;

        int diff = num2 - num1;
        bool is_increase = (diff > 0) ? true : false;

        while (is_continue)
        {
            diff = num2 - num1;

            diff = (is_increase) ? diff : (diff * (-1));

            if (!(1 <= diff && diff <= 3))
            {
                is_safe = false;
                break;
            }

            if (getline(ss, val, ' '))
            {
                num1 = num2;
                num2 = stoi(val);
            }
            else
            {
                is_continue = false;
            }
        }

        if (is_safe)
        {
            ++safe_counter;
        }
    }

    input_file.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day2 Q1: Result: " << safe_counter << "\t| Time: " << elapsed.count() << "ms" << endl;
}

void Day2::q2() const
{
    auto start = std::chrono::high_resolution_clock::now();

    auto input_file = ISolution::get_file_handler("inputs/day2.txt").value();

    string line;
    int safe_counter = 0;
    int lin_num = 0;
    while (getline(input_file, line))
    {
        lin_num++;
        string val;
        stringstream ss(line);

        vector<int> vec;
        bool is_recoverable = true;

        while (getline(ss, val, ' '))
        {
            vec.emplace_back(stoi(val));
        }

        if (is_safe_report(vec))
        {
            ++safe_counter;
        }
        else
        {
            int skip_index = 0;
            vector<int> new_vector;
            
            for (int i = 0; i < vec.size(); ++i)
            {
                copy_if(vec.begin(), vec.end(),
                        back_inserter(new_vector),
                        [skip_index, i](int x) mutable
                        {
                            bool res = (i != skip_index);
                            ++skip_index;
                            return res;
                        });

                if (is_safe_report(new_vector))
                {
                    ++safe_counter;
                    break;
                }
                skip_index = 0;
                new_vector.clear();
            }
        }
    }

    input_file.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day2 Q2: Result: " << safe_counter << "\t| Time: " << elapsed.count() << "ms" << endl;
}

bool Day2::is_safe_report(std::vector<int> &vec) const
{
    bool is_safe = true;
    int diff = vec[1] - vec[0];

    bool is_increase = (diff > 0);
    for (int i = 1; i < vec.size(); ++i)
    {
        diff = vec[i] - vec[i - 1];

        diff = (is_increase) ? diff : (diff * (-1));

        if (!(1 <= diff && diff <= 3))
        {
            is_safe = false;
            break;
        }
    }

    return is_safe;
}
