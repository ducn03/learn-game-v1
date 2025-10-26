#pragma once
#include <SFML/Graphics.hpp>
#include "core/scenes/SceneManager.h"

class Game {
private:
    sf::RenderWindow window;
    SceneManager sceneManager;
    bool isRunning = true;

public:
    Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();
};
