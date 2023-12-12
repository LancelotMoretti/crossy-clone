#include "traffic.hpp"

Traffic::Traffic(TextureHolder* holder, const Vec2& size, const Vec2& pos, const Vec2& off, bool isRed, int clock): 
    holder(holder),
    Isometric(holder->get("TRAFFIC_GREEN"), size, pos),
    isRed(isRed),
    interval(300),
    clock(clock) {}

void Traffic::process() {
    if (clock >= interval) {
        isRed = !isRed;
        clock = 0;
        
        if (isRed) texture = holder->get("TRAFFIC_GREEN");
        else texture = holder->get("TRAFFIC_RED");
        
        return;
    }

    ++clock;
}

bool Traffic::isRedLight() const {
    return isRed;
}

int Traffic::getClock() const {
    return clock;
}