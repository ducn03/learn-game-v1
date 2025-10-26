#pragma once
#include <memory>
#include <stack>
#include "Scene.h"

class SceneManager {
private:
    std::stack<std::shared_ptr<Scene>> scenes;

public:
    void changeScene(const std::shared_ptr<Scene>& newScene);
    void handleEvent(const sf::Event& event);
    void update(float dt);
    void render(sf::RenderWindow& window);
};
