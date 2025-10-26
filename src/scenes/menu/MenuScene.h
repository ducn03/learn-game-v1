#pragma once

#include <SFML/Graphics.hpp>
#include "../../components/menu/Menu.h"
#include "core/scenes/Scene.h"

class MenuScene final : public Scene {
public:
    MenuScene(sf::RenderWindow& win, SceneManager& mgr);

    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    SceneManager& sceneManager;
    Menu menu;
};
