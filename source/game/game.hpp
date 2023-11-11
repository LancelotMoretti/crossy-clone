#ifndef GAME_HPP_
#define GAME_HPP_

#include <windows.h>
#include <chrono>
#include <string>
#include <filesystem>

#include "engine.hpp"

using namespace std::chrono;
using widestring = std::wstring;

class Game {
private:
    HWND window;
    HDC hdc;
    Engine* engine;

    int width, height, scale, frames;
    float framesAVG;

    std::string title;
    widestring path;
    high_resolution_clock::time_point epoch, prev;
    
    int cur = 0, numcur = 1;
    byte count[3] = { 1, 1, 1 }, num[3] = { 1, 1, 1 };

    Game(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(Game&&) = delete;
    Game& operator=(const Game&) = delete;

    void initialize();
	void render();
	void process();
	void playsound();
	
    std::string debugInfo();

public:
    Game();
    ~Game();
    
    void run();
};

#endif