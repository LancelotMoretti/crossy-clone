#ifndef MENU_HPP_
#define MENU_HPP_

#include <vector>

#include "scene.hpp"
#include "scene_registry.hpp"

class Menu : public Scene {
private:
    bool isContinueEnabled;
    int defaultButton;
    int button; // 0 = continue, 1 = start, 2 = option, 3 = leaderboard, 4 = credit, 5 = quit

    const Texture TITLE;
    const Texture CONTINUE, CONTINUE_CLICKED;
    const Texture START, START_CLICKED;
    const Texture OPTION, OPTION_CLICKED;
    const Texture LEADERBOARD, LEADERBOARD_CLICKED;
    const Texture CREDIT, CREDIT_CLICKED;
    const Texture QUIT, QUIT_CLICKED;
    const Texture DUCK_X2;
    Sound button_clicked;
    Object title;
    Object duck_x2;

    std::vector<Button*> buttons;

public:
    Menu(int width, int height, Engine* engine, Speaker* speaker, SceneRegistry* registry, Setting* setting, Keyboard* keyboard);
    ~Menu();

    void updateButton();
    Scene* process() override;
    void render() override;
    void playsound() override;
};

#endif /* MENU_HPP_ */