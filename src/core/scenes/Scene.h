#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class SceneManager;

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
