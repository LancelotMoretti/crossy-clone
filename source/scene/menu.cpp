#include "menu.hpp"

Menu::Menu(Engine* engine, AudioDevice* audio, SceneRegistry* registry, Setting* setting, Keyboard* keyboard) : 
    Scene(engine, audio, registry, setting, keyboard),
    title(0, 0, Texture("asset/texture/title.bmp")) {}

Scene* Menu::process() {
    int button = 1;
    bool isExit = false;

    Scene* next = this;
    Key pressedKey = keyboard->key();

    switch(pressedKey) {
    case Key::UP:
        if(button > 1) {
            button--;
        }
        break;
    case Key::DOWN:
        if(button < 5) {
            button++;
        }
        break;
    case Key::ENTER:
        switch(button) {
        case 1:
            next = sceneRegistry->scene(SceneID::MENU);
            break;
        case 2:
            next = sceneRegistry->scene(SceneID::OPTION);
            break;
        case 3:
            next = sceneRegistry->scene(SceneID::LEADERBOARD);
            break;
        case 4:
            next = sceneRegistry->scene(SceneID::CREDIT);
            break;
        case 5:
            isExit = true;
            break;
        }
        break;
    }

    return next;
}

void Menu::render() {
    title.render(engine);
}

void Menu::playsound() {
}

Menu::~Menu() {
}