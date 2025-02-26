#pragma once

#include <iostream>
#include <chrono>

class ISolution {
public:
    virtual ~ISolution() = default;

    virtual void run() = 0;
};
