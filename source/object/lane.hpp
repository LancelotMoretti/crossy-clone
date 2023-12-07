#ifndef LANE_HPP_
#define LANE_HPP_

#include <vector>
#include <utility>

#include "vehicle.hpp"
#include "traffic.hpp"

class Lane : public Isometric {
private:
    int length;
    float speed;

    int spawn;
    int clock;

    std::vector<std::pair<const Texture&, const Texture&>> VEHICLE_TEXTURE;
    std::pair<const Texture&, const Texture&> TRAFFIC_TEXTURE;
    
    std::vector<Vehicle*> vehicles;
    Traffic traffic;

    std::vector<Isometric> blocks;


public:
    Lane(const Texture& texture, int pos, int len, float speed, const std::vector<std::pair<const Texture&, const Texture&>>& VT, const std::pair<const Texture&, const Texture&>& TT, bool trafficState = false, int clock = 0, int spawn = 120);

    void render(Engine* engine, int playerPos);
    void process(bool& isGameover, float playerPos = -1.0f);
    void gameoverProcess(bool& isStopped, float playerPos = -1.0f);

    bool collide(float pos);
    float getSpeed() const;
    int getSpawn() const;
    void addVehicle(float pos);
    std::vector<char> getTrafficGamestate() const;
    std::vector<char> getVehiclesGamestate() const;

    ~Lane();
};

#endif