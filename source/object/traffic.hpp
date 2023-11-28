#ifndef TRAFFIC_HPP_
#define TRAFFIC_HPP_

#include <iostream>

class Traffic {
private:
    int lane;
    bool isRed;  // true = red, false = green
    int clock;
    std::string sprite;

public:
    Traffic(const int& lane, const bool& isRed, const int& clock, const std::string& sprite);

    void render();
    void process(const int& time);
    bool isRedLight();

    ~Traffic();
};

#endif