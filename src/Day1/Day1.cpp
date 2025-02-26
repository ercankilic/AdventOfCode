#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib> // For std::abs

#include "Day1.hpp"

using namespace std;
namespace fs = std::filesystem;

void Day1::run()
{
    q1();
    q2();
}

void Day1::q1()
{
    auto start = std::chrono::high_resolution_clock::now();

    fs::path file_path = "inputs/day1_q1.txt";

    if (!fs::exists(file_path))
    {
        cerr << "File does not exist." << endl;
        return;
    }

    ifstream input_file(file_path);

    if (!input_file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    string line;
    vector<int> vec1, vec2;

    while (getline(input_file, line))
    {
        const auto i = line.find(" ");

        auto v1 = line.substr(0, i);
        auto v2 = line.substr(i);

        v1.erase(remove_if(v1.begin(), v1.end(), ::isspace), v1.end());
        v2.erase(remove_if(v2.begin(), v2.end(), ::isspace), v2.end());

        vec1.emplace_back(stoi(v1));
        vec2.emplace_back(stoi(v2));
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    int sum = 0;

    for (int i = 0; i < vec1.size(); i++)
    {
        sum += (abs(vec1[i] - vec2[i]));
    }

    input_file.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day1 Q1: Result: " << sum << "\t| Time: " << elapsed.count() << "ms" << endl;
}

void Day1::q2()
{
    auto start = std::chrono::high_resolution_clock::now();

    fs::path file_path = "inputs/day1_q1.txt";

    if (!fs::exists(file_path))
    {
        cerr << "File does not exist." << endl;
        return;
    }

    ifstream input_file(file_path);

    if (!input_file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    string line;
    vector<int> data1;
    map<int, int> data2;

    while (getline(input_file, line))
    {
        const auto i = line.find(" ");

        auto v1 = line.substr(0, i);
        auto v2 = line.substr(i);

        v1.erase(remove_if(v1.begin(), v1.end(), ::isspace), v1.end());
        v2.erase(remove_if(v2.begin(), v2.end(), ::isspace), v2.end());

        data1.emplace_back(stoi(v1));
        auto tmp_v2 = stoi(v2);
        if(data2.contains(tmp_v2)) {
            data2[stoi(v2)]++;
        }
        else {
            data2[stoi(v2)] = 1;
        }
    }

    int sum = 0;

    for (int i = 0; i < data1.size(); i++)
    {
        sum += (data1[i] * data2[data1[i]]);
    }

    input_file.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Day1 Q2: Result: " << sum << "\t| Time: " << elapsed.count() << "ms" << endl;
}
