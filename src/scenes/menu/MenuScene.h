// MenuScene.h
#pragma once
#include <SFML/Graphics.hpp>
#include "../../components/menu/Menu.h"
#include "core/scenes/SceneManager.h"

class MenuScene : public Scene {
public:

    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

    MenuScene(sf::RenderWindow& win, SceneManager& mgr);

private:
    sf::RenderWindow& window;
    SceneManager& sceneManager;
    Menu menu;
};
