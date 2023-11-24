#ifndef SETTING_HPP_
#define SETTING_HPP_

#include <windows.h>

#include <fstream>
#include <iostream>
#include <utility>

#include "typedef.hpp"

class Setting {
private:
    byte score[12];  // Saving 3 highscores as a byte array to keep endianess consistent
    Volume music, sfx;
    Sprite sprite;

    bool load();
    void save();

public:
    Setting();
    ~Setting();

    word highscore(byte rank);
    Volume volMusic();
    Volume volSFX();
    Sprite spriteID();

    void setScore(word score);
    void setSprite(Sprite sprite);

    void incMusic();
    void decMusic();

    void incSFX();
    void decSFX();
};

#endif