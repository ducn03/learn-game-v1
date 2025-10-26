#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "components/button/Button.h"
#include "core/scenes/Scene.h"

class SceneManager;

class MenuScene : public Scene {
public:
    MenuScene(sf::RenderWindow& win, SceneManager& mgr);
    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    SceneManager& sceneManager;
    sf::Font font;
    sf::Text title;
    std::vector<Button> buttons;
    int selectedIndex = 0;
};
