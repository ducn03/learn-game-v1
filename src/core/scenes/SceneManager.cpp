#include "SceneManager.h"

void SceneManager::changeScene(const std::shared_ptr<Scene>& newScene) {
    while (!scenes.empty()) scenes.pop();
    scenes.push(newScene);
}

void SceneManager::handleEvent(const sf::Event& event) {
    if (!scenes.empty()) scenes.top()->handleEvent(event);
}

void SceneManager::update(const float dt) {
    if (!scenes.empty()) scenes.top()->update(dt);
}

void SceneManager::render(sf::RenderWindow& window) {
    if (!scenes.empty()) scenes.top()->render(window);
}
