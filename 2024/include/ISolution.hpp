#pragma once

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>

class ISolution
{
  public:
    virtual ~ISolution() = default;

    virtual void run() = 0;

    std::optional<std::ifstream> get_file_handler(std::filesystem::path path) const
    {
        if (!std::filesystem::exists(path))
        {
            std::cerr << "File does not exist. Path: " << path << std::endl;
            return std::nullopt;
        }

        std::ifstream input_file(path);

        if (!input_file.is_open())
        {
            std::cerr << "Failed to open the file. Path: " << path << std::endl;
            return std::nullopt;
        }

        return input_file;
    }
};
