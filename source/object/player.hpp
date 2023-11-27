#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>

class Player {
private:
    int lane;
    float pos;
    std::string sound;   // sound
    std::string sprite;  // sprite

public:
    void move();
    int getPos();
    void render();
    void playSound();
};

#endif