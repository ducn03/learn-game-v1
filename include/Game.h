//
// Created by DinhDuc on 26/10/2025.
//

#ifndef LEARN_GAME_V1_GAME_H
#define LEARN_GAME_V1_GAME_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"


class Game {
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::RectangleShape player;
    float playerSpeed;
    bool running;

    void processEvents();
    void update(float dt);
    void render();
    void handleInput(float dt);

public:
    Game();
    void run();
};

#endif //LEARN_GAME_V1_GAME_H